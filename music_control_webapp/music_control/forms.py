from django.forms import ModelForm
from .models import MusicNotes

class MusicNotesForm(ModelForm):
    class Meta:
        model = MusicNotes
        fields = ['notes']
