# Generated by Django 4.0.3 on 2022-04-01 16:37

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('main_server', '0002_statusmessage'),
    ]

    operations = [
        migrations.CreateModel(
            name='MusicSelection',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('selection', models.CharField(max_length=10000)),
            ],
        ),
    ]
