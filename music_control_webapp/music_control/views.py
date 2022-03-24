from django.shortcuts import render
from django.http import HttpResponse
from .forms import StringInputForm
from django.template import RequestContext

# Create your views here.
def index(request):
    return render(request, 'index.html')

def arduino_button(request):
    if request.method == 'POST':
        form = StringInputForm(request.POST)
        if(form.is_valid()):
            return form.cleaned_data['input']
    else:
        form = StringInputForm()
        return render(request, 'arduino/button.html', {'form': form})