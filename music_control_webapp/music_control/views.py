from django.shortcuts import render
from .forms import MusicNotesForm
from django.http import HttpResponse
from .models import MusicNotes

# Create your views here.
def index(request):
    return render(request, template_name='index.html')

def arduino_button(request):
    if request.method == 'POST':
        form = MusicNotesForm(request.POST)
        if(form.is_valid()):
            form.save()
    else:
        form = MusicNotesForm()
    return render(request, 'arduino/button.html', {'form': form})

def get_value(request):
    return HttpResponse(MusicNotes.objects.last().notes)
