from setuptools import find_packages
from setuptools import setup

setup(
    name='server',
    version='0.0.0',
    packages=find_packages(
        include=('server', 'server.*')),
)
