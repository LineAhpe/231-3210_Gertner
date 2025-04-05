from django.db import models

# Create your models here.

class StorageFacilities(models.Model):
    address = models.CharField(max_length=64, null=True)
    typename = models.CharField(max_length=32, null=True)
    capacity = models.IntegerField(null=True)
    square= models.IntegerField(null=True)
    main_of_storage = models.CharField(max_length=32, null=True)