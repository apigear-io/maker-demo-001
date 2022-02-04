// core api for module {{module}}

{% for enum in module.enums %}

// {{enum.description}}
enum {{enum.name}} {
{% for member in enum.members %}    
    {{member.name}} = {{member.value}}, // {{enum.description}}
{% endfor %}
};
{% endfor %}


{% for struct in module.structs %}

// {{struct.name}}
class {{struct.name}} {
public:
    {{struct.name}}();
    virtual ~{{struct.name}}();

{% for field in struct.fields %}
public:
    // {{field.description}}
    {{field.type}} {{field.name}}() const;
    void set{{field.name|upperFirst}}({{field|cpp14Param}});
{% endfor %}
};
{% endfor %}

{% for interface in module.interfaces %}

{% endfor %}

{% for interface in module.interfaces %}

// interface {{interface.name}}
// {{interface.description}}
class {{interface.name}} {
public:
    {{interface.name}}();
    virtual ~{{interface.name}}();

public: // properties
{% for property in interface.properties %}
    // {{property.description}}
    virtual {{property|cpp14Return}} {{property.name}}() const = 0;
    virtual void set{{property.name|upperFirst}}({{property|cpp14Param}} value) = 0;
{% endfor %}

public: // operations
{% for operation in interface.operations %}
    // {{operation.description}}
    virtual {{operation|cpp14Return}} {{operation.name}}({{operation|cpp14Params}}) = 0;
{% endfor %}
};
{% endfor %}