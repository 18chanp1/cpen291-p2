import json
from django.http import HttpResponse
from django.shortcuts import render
from .models import MusicNotes, StatusMessage
from django.views.decorators.csrf import csrf_exempt

def test(request):
    return HttpResponse("Hello World")

def index(request):
    return render(request, template_name='index.html')

@csrf_exempt
def input(request):
    if request.method == 'POST':
        music_input = MusicNotes(notes=json.loads(request.body.decode('utf-8'))["arguments"])
        if music_input:
            music_input.save()
        return HttpResponse("YAY")
    elif request.method == 'GET':
        return HttpResponse(MusicNotes.objects.last().notes)

@csrf_exempt
def status(request):
    if request.method == 'POST':
        hdw_status = StatusMessage(msg = json.loads(request.body.decode('utf-8'))['status'])
        if hdw_status:
            hdw_status.save()
        return HttpResponse("YAY")
    elif request.method == 'GET':
        return render(request, template_name = 'index.html') #TODO: should change to related html
