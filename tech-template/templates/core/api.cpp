// core api for {{module}}

#include "api.h"

    
{% for interface in module.interfaces %}

// {{interface.name}}

{{interface.name}}::{{interface.name}}() {
}

{{interface.name}}::~{{interface.name}}() {
}
{% endfor %}