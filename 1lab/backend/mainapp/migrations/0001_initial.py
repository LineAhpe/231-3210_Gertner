# Generated by Django 5.1.6 on 2025-02-08 14:41

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='StorageFacilities',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('address', models.CharField(max_length=64, null=True)),
                ('typename', models.CharField(max_length=32, null=True)),
                ('number', models.CharField(max_length=12, null=True)),
                ('square', models.CharField(max_length=12, null=True)),
                ('main_of_storage', models.CharField(max_length=32, null=True)),
            ],
        ),
    ]
