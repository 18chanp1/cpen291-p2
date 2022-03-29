from django.http import HttpResponse
from django.shortcuts import render
from .models import MusicNotes

def test(request):
    return HttpResponse("Hello World")

def index(request):
    return render(request, template_name='index.html')

def input(request):
    if request.method == 'POST':
        music_input = MusicNotes(notes=request.POST['arguments'])
        if music_input:
            music_input.save()
    elif request.method == 'GET':
        return HttpResponse(MusicNotes.objects.last().notes)

