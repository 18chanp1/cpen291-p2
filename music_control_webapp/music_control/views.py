from django.shortcuts import render
from .forms import MusicNotesForm
from django.http import HttpResponse
from .models import MusicNotes

# Create your views here.
def index(request):
    return render(request, 'index.html')

def arduino_button(request):
    # next page to get to after submission
    if request.method == 'POST':
        form = MusicNotesForm(request.POST)
        if(form.is_valid()):
           form.save()
    else:
        form = MusicNotesForm()
        return render(request, 'arduino/button.html', {'form': form})

def get_value(request):
    music_input_list = MusicNotes.objects.all()
    for music in music_input_list:
        print(music.notes)
    return music_input_list[len(music_input_list)-1]   

