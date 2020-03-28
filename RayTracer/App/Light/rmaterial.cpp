#include "rmaterial.h"

RMaterial::RMaterial():color(1,1,1),ambient(0.1),diffuse(0.9),specular(0.9),shininess(200){};

bool RMaterial::operator==(const RMaterial& m)const {
    return m.color==color and m.ambient==ambient and m.diffuse==diffuse and m.specular==specular and m.shininess==shininess;
}

RColor lighting(RMaterial m,RPointLight light,RPoint point,RVector eyev,RVector normalv) {
    RColor effective_color=m.color*light.intensity;
    RVector lightv=(light.position-point).normalize();
    RColor ambient=effective_color*m.ambient;
    float light_dot_normal=lightv*normalv;
    RColor diffuse;
    RColor specular;
//    eyev=eyev.normalize();
    if(light_dot_normal<0) {
        diffuse.r=0;
        diffuse.g=0;
        diffuse.b=0;

        specular.r=0;
        specular.g=0;
        specular.b=0;
    }
    else {
        diffuse=effective_color*m.diffuse*light_dot_normal;

        RVector reflectv=(-lightv).reflect(normalv);
        float reflect_dot_eye=reflectv*eyev;
        if(reflect_dot_eye<=0) {
            specular.r=specular.g=specular.b=0;
        }
        else {
            double factor=pow(reflect_dot_eye,m.shininess);
            specular=light.intensity*m.specular*factor;
        }
    }
    return ambient+diffuse+specular;
}
