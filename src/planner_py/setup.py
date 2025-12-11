from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'planner_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (
            os.path.join('share', package_name, 'launch'),
            glob(os.path.join('launch', '*.launch.py'))
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robprakt2',
    maintainer_email='robprakt2@todo.todo',
    description='TODO: Package description',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'state_node=planner_py.state_node:main',
            'test_planner_node=planner_py.test_planner_node:main',
        ],
    },
)
