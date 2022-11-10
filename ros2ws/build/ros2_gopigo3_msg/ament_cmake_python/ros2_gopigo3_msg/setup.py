from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_gopigo3_msg',
    version='0.0.0',
    packages=find_packages(
        include=('ros2_gopigo3_msg', 'ros2_gopigo3_msg.*')),
)
