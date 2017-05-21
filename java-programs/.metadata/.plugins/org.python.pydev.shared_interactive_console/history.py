import sys; print('%s %s' % (sys.executable or sys.platform, sys.version))
import os; os.environ['DJANGO_SETTINGS_MODULE'] = 'pathshala.settings'; import django
if django.get_version() < '1.5':
    from django.core import management
    import pathshala.settings as settings
    management.setup_environ(settings)
if django.get_version() >= '1.7':
    from django.core.wsgi import get_wsgi_application
    application = get_wsgi_application()
import sys; print('%s %s' % (sys.executable or sys.platform, sys.version))
import os
os.getcwd()
