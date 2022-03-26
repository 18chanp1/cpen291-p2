from django.shortcuts import render
from .forms import StringInputForm
from django.http import HttpResponse
from music_control.models import MusicNotes

# Create your views here.
def index(request):
    return render(request, 'index.html')

def arduino_button(request):
    if request.method == 'POST':
        form = StringInputForm(request.POST)
        if(form.is_valid()):
	    string_input = form.cleaned_data['input']
	    try:
       	    	instance = MusicNotes(notes = string_input)
            	instance.save()
	    except Exception as e:
		print(e)
            return HttpResponse(string_input)
    else:
        form = StringInputForm()
        return render(request, 'arduino/button.html', {'form': form})

def get_value(request):
    allInputs = MusicNotes.objects.all()
    for music_input in allInputs:
        print(music_input.notes)   

