from django.contrib import admin
from django.urls import path
from django.conf import settings
from django.conf.urls.static import static


from rest_framework import routers

from mainapp.views import StorageViewSet

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/storage', StorageViewSet.as_view({'get': 'list', 'post': 'create'})),
    path('api/storage/<pk>', StorageViewSet.as_view({'get': 'retrieve', 'delete': 'destroy', 'patch': 'update', 'put': 'update'})),
    # path('storage', StorageViewSet.as_view({'post': 'create'}))
]

urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)