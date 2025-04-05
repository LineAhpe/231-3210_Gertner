import random, string, datetime
from .models import *
from django.db import transaction
import faker
from faker import Faker
from django.contrib.auth.models import Group, User


fk = Faker()



def gentestdata():
    # try:
    with transaction.atomic():
        for i in range(1000):
            new_storage = StorageFacilities()
            new_storage.address=fk.address()
            new_storage.typename=random.choice(['Холодильный', 'Морозильный', 'Сухой', 'Отапливаемый'])
            new_storage.capacity=random.randint(100, 10000)
            new_storage.square=random.randint(50, 5000)
            new_storage.main_of_storage=fk.name()
            new_storage.save()
    # <<< тут заканчивается транзакция
    print('OK gentestdata()')

import os

def clear_data():
    StorageFacilities.objects.all().delete()

if __name__ == '__main__':
        gentestdata()
