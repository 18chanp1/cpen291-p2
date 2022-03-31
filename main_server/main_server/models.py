from django.db import models

# this is the model class with all the objects that were stored into the database
class MusicNotes(models.Model):
    notes = models.CharField(max_length=10000)
    
class StatusMessage(models.Model):
    msg = models.CharField(max_length=10000)
    
class MusicSelection(models.Model):
    selection = models.CharField(max_length=10000)