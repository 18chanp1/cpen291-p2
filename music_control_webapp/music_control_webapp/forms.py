from django.forms import ModelForm
from .models import MusicNotes

class MusicNotesForm(ModelForm):
    model = MusicNotes
    fields = ['notes']