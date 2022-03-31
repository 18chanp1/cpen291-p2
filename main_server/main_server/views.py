import json
from django.http import HttpResponse
from django.shortcuts import render
from .models import MusicNotes, StatusMessage, MusicSelection
from django.views.decorators.csrf import csrf_exempt

# test page will not be shown
def test(request):
    return HttpResponse("Hello World")

# home page, return control to frontend
def index(request):
    return render(request, template_name='index.html')

# for post requests, csrf token are exempted for simplicity

# upload music input 
@csrf_exempt
def input(request):
    # post request from frontend that provides the notes to play 
    # api list provided in appendix of report
    if request.method == 'POST':
        data = json.loads(request.body.decode('utf-8')) # load json data 
        music_input = MusicNotes(notes=data["arguments"]) # get notes
        if music_input: # save if there's some input
            music_input.save()
            return HttpResponse("YAY")
        else:
            return HttpResponse("Invalid Input")
    # get request from arduino for notes to play
    elif request.method == 'GET': # return the newest input 
        return HttpResponse(MusicNotes.objects.last().notes)

@csrf_exempt
def status(request):
    # post request from arduino with current status
    if request.method == 'POST':
        print(request.body)
        arduino_status = StatusMessage.objects.get(id=1) # continously overwrite the first line
        arduino_status.msg = request.body.decode('utf-8') # decode binary sent from arduino 
        arduino_status.save() # save object
        return HttpResponse("saved")
    # get request from web server for current status
    elif request.method == 'GET':
        if StatusMessage.objects.get(id=1).msg == 'playing':
            return HttpResponse("PLAYING")
        elif StatusMessage.objects.get(id=1).msg == 'free':
            return HttpResponse("FREE")

@csrf_exempt
def selection(request):
    # post request with user selection of song
    if request.method == 'POST':
        data = json.loads(request.body.decode('utf-8')) # decode json
        music_selection = MusicSelection(selection = data['arguments']) # create object
        if music_selection: # save if object exist 
            music_selection.save()
            return HttpResponse("YAY")
        else:
            return HttpResponse("invalid input")
    # get request from arduino to know which song to play
    elif request.method == 'GET':
        return HttpResponse(MusicSelection.objects.last().notes)
    
@csrf_exempt
def toggle(request):
    # post request from frontend with current input mode
    if request.method == 'POST':
        data = json.loads(request.body.decode('utf-8'))
        control_mode = StatusMessage.objects.get(id=0)
        control_mode.msg = data['arguments']
        control_mode.save()
        return HttpResponse("saved")
    # get request from arduino to determine current input mode
    elif request.method == 'GET':
        return HttpResponse(StatusMessage.objects.get(id=0).msg)