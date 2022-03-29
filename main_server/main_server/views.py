import json
from django.http import HttpResponse
from django.shortcuts import render
from .models import MusicNotes
from django.views.decorators.csrf import csrf_exempt

def test(request):
    return HttpResponse("Hello World")

def index(request):
    return render(request, template_name='index.html')

@csrf_exempt
def input(request):
    if request.method == 'POST':
        #print(request.body)
        music_input = MusicNotes(notes=json.loads(request.body.decode('utf-8'))["arguments"])
        if music_input:
            music_input.save()
        return HttpResponse("YAY")
    elif request.method == 'GET':
        return HttpResponse(MusicNotes.objects.last().notes)


