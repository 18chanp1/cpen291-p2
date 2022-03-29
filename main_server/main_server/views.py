from django.http import HttpResponse
from django.shortcuts import render
def test(request):
    return HttpResponse("Hello World")

def index(request):
    return render(request, template_name='index.html')