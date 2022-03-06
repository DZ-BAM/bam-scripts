/*
 * World building functions.
 */
#ifndef DZBAM_WORLDBUILDER
#define DZBAM_WORLDBUILDER

class DZBAM_Object
{
    string name;
    vector position;
    vector orientation;

    void Spawn()
    {
        Object obj = Object.Cast(GetGame().CreateObject(name, position));

        if (obj == null)
            return;

        obj.SetAffectPathgraph(true, false);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
        obj.SetPosition(position);
        obj.SetOrientation(orientation);
    }
}


typedef array<DZBAM_Object> DZBAM_Objects;


ref DZBAM_Objects DZBAM_LoadObjects(string filename)
{
    DZBAM_Objects objects = new DZBAM_Objects;
    JsonFileLoader<DZBAM_Objects>.JsonLoadFile(filename, objects);
    return objects;
}

void DZBAM_CreateObjects(ref DZBAM_Objects objects)
{
    foreach(DZBAM_Object obj: objects)
    obj.Spawn();
}

void DZBAM_CreateObjects(string filename)
{
    DZBAM_CreateObjects(DZBAM_LoadObjects(filename));
}

#endif
