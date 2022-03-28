from django.db import models

class MusicNotes(models.Model):
    notes = models.CharField(max_length=10000)
