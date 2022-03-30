from django.db import models

class MusicNotes(models.Model):
    notes = models.CharField(max_length=10000)
    
class StatusMessage(models.Model):
    msg = models.CharField(max_length=10000)