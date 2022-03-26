from django.forms import ModelForm
from music_control.models import MusicNotes

class MusicNotesForm(ModelForm):
    model = MusicNotes
    fields = ['notes']