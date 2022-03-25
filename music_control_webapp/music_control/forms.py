from django import forms

class StringInputForm(forms.Form):
    input = forms.CharField(label = "input", max_length=1000, initial="John")