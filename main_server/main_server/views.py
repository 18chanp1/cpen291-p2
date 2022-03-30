import json
from django.http import HttpResponse
from django.shortcuts import render
from .models import MusicNotes, StatusMessage, MusicSelection
from django.views.decorators.csrf import csrf_exempt

def test(request):
    return HttpResponse("Hello World")

def index(request):
    return render(request, template_name='index.html')

@csrf_exempt
def input(request):
    if request.method == 'POST':
        data = json.loads(request.body.decode('utf-8'))
        music_input = MusicNotes(notes=data["arguments"])
        if music_input:
            music_input.save()
            return HttpResponse("YAY")
        else:
            return HttpResponse("Invalid Input")
    elif request.method == 'GET':
        return HttpResponse(MusicNotes.objects.last().notes)

@csrf_exempt
def status(request):
    if request.method == 'POST':
        print(request.body)
        arduino_status = StatusMessage.objects.get(id=1)
        arduino_status.msg = request.body.decode('utf-8')
        arduino_status.save()
        return HttpResponse("saved")
    elif request.method == 'GET':
        if StatusMessage.objects.get(id=1).msg == 'playing':
            return HttpResponse("PLAYING") #TODO: should change to related playing page here
        elif StatusMessage.objects.get(id=1).msg == 'free':
            return render(request, template_name = 'index.html')

@csrf_exempt
def selection(request):
    if request.method == 'POST':
        data = json.loads(request.body.decode('utf-8'))
        music_selection = MusicSelection(selection = data['arguments'])
        if music_selection:
            music_selection.save()
            return HttpResponse("YAY")
        else:
            return HttpResponse("invalid input")
    elif request.method == 'GET':
        return HttpResponse(MusicSelection.objects.last().notes)
    
@csrf_exempt
def toggle(request):
    if request.method == 'POST':
        data = json.loads(request.body.decode('utf-8'))
        control_mode = StatusMessage.objects.get(id=2)
        control_mode.msg = data['arguments']
        control_mode.save()
        return HttpResponse("saved")
    elif request.method == 'GET':
        return HttpResponse(StatusMessage.objects.get(id=2).msg)