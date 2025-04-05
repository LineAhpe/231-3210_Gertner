from rest_framework import serializers
from .models import StorageFacilities

class StorageSerializer(serializers.ModelSerializer):

    class Meta:
        model = StorageFacilities
        fields = '__all__'