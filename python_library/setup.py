from setuptools import find_packages, setup

setup(
    name='pictlogger',
    packages=find_packages(include=['pictlogger']),
    version='0.1.0',
    description='Simple logger writen in c++',
    author='Ilya Dudelzak',
    install_requires=[],
    setup_requires=['pytest-runner'],
    tests_require=['pytest==4.4.1'],
    test_suite='tests',
    package_data={'': ['pictlogger.so']},
)
