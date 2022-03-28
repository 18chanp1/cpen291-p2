# Create your views here.
from .forms import MusicNotesForm
from django.http import HttpResponse
def input(request):
    form = MusicNotesForm(request.POST)
    if(form.is_valid()):
        form.save()
        
def test(request):
    return HttpResponse('hello')