from django.urls import path
from . import views


app_name = 'music_control'

urlpatterns = [
    path('', views.index, name = 'index'),
    path('arduino/value', views.get_value, name='get_value'),
    path('arduino/button', views.arduino_button, name='arduino_button'),
]
