from django.shortcuts import render

from django.conf import settings

import rest_framework
from rest_framework import viewsets
from .models import StorageFacilities
from .serializers import StorageSerializer


class StorageViewSet(viewsets.ModelViewSet):
    queryset = StorageFacilities.objects.all()
    serializer_class = StorageSerializer

    def retrieve(self, request, *args, **kwargs):
        return super().retrieve(request, *args, **kwargs)

    def create(self, request, *args, **kwargs):
        return super().create(request, *args, **kwargs)

    def update(self, request, *args, **kwargs):
        return super().update(request, *args, **kwargs)

    def destroy(self, request, *args, **kwargs):
        return super().destroy(request, *args, **kwargs)

    def list(self, request, *args, **kwargs):
        return super().list(request, *args, **kwargs)