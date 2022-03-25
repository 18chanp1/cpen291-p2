from django.shortcuts import render
from .forms import StringInputForm
from django.http import HttpResponse

string_input = ""
# Create your views here.
def index(request):
    return render(request, 'index.html')

def arduino_button(request):
    if request.method == 'POST':
        form = StringInputForm(request.POST)
        if(form.is_valid()):
            string_input = form.cleaned_data['input']
            return HttpResponse(string_input)
    else:
        form = StringInputForm()
        return render(request, 'arduino/button.html', {'form': form})

def get_value():
    return string_input
    