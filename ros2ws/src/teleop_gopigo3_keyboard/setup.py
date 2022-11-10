from setuptools import setup

package_name = 'teleop_gopigo3_keyboard'

setup(
    name=package_name,
    version='2.3.2',
    packages=[],
    py_modules=[
        'teleop_gopigo3_keyboard'
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='slowrunner',
    maintainer_email='slowrunner@noreply.com',
    author='mods Alan McDonley',
    keywords=['ROS'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: BSD',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],
    description='A GoPiGo3 teleoperation node to convert keyboard'
                'commands to Twist messages.',
    license='BSD',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'teleop_gopigo3_keyboard = teleop_gopigo3_keyboard:main'
        ],
    },
)
