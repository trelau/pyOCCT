/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_Selection.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <NCollection_Vector.hxx>
#include <SelectMgr_SensitiveEntity.hxx>
#include <SelectMgr_TypeOfUpdate.hxx>
#include <SelectMgr_TypeOfBVHUpdate.hxx>
#include <SelectMgr_StateOfSelection.hxx>

void bind_SelectMgr_Selection(py::module &mod){

py::class_<SelectMgr_Selection, opencascade::handle<SelectMgr_Selection>, Standard_Transient> cls_SelectMgr_Selection(mod, "SelectMgr_Selection", "Represents the state of a given selection mode for a Selectable Object. Contains all the sensitive entities available for this mode. An interactive object can have an indefinite number of modes of selection, each representing a 'decomposition' into sensitive primitives; each primitive has an Owner (SelectMgr_EntityOwner) which allows us to identify the exact entity which has been detected. Each Selection mode is identified by an index. The set of sensitive primitives which correspond to a given mode is stocked in a SelectMgr_Selection object. By Convention, the default selection mode which allows us to grasp the Interactive object in its entirety will be mode 0. AIS_Trihedron : 4 selection modes - mode 0 : selection of a trihedron - mode 1 : selection of the origin of the trihedron - mode 2 : selection of the axes - mode 3 : selection of the planes XOY, YOZ, XOZ when you activate one of modes 1 2 3 4 , you pick AIS objects of type: - AIS_Point - AIS_Axis (and information on the type of axis) - AIS_Plane (and information on the type of plane). AIS_PlaneTrihedron offers 3 selection modes: - mode 0 : selection of the whole trihedron - mode 1 : selection of the origin of the trihedron - mode 2 : selection of the axes - same remarks as for the Trihedron. AIS_Shape : 7 maximum selection modes, depending on the complexity of the shape : - mode 0 : selection of the AIS_Shape - mode 1 : selection of the vertices - mode 2 : selection of the edges - mode 3 : selection of the wires - mode 4 : selection of the faces - mode 5 : selection of the shells - mode 6 : selection of the constituent solids.");

// Constructors
cls_SelectMgr_Selection.def(py::init<>());
cls_SelectMgr_Selection.def(py::init<const Standard_Integer>(), py::arg("theModeIdx"));

// Fields

// Methods
cls_SelectMgr_Selection.def_static("get_type_name_", (const char * (*)()) &SelectMgr_Selection::get_type_name, "None");
cls_SelectMgr_Selection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_Selection::get_type_descriptor, "None");
cls_SelectMgr_Selection.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_Selection::*)() const) &SelectMgr_Selection::DynamicType, "None");
cls_SelectMgr_Selection.def("Destroy", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Destroy, "None");
cls_SelectMgr_Selection.def("Add", (void (SelectMgr_Selection::*)(const opencascade::handle<SelectBasics_SensitiveEntity> &)) &SelectMgr_Selection::Add, "Adds the sensitive primitive to the list of stored entities in this object. Raises NullObject if the primitive is a null handle.", py::arg("theSensitive"));
cls_SelectMgr_Selection.def("Clear", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Clear, "empties the selection from all the stored entities");
cls_SelectMgr_Selection.def("IsEmpty", (Standard_Boolean (SelectMgr_Selection::*)() const) &SelectMgr_Selection::IsEmpty, "returns true if no sensitive entity is stored.");
cls_SelectMgr_Selection.def("Mode", (Standard_Integer (SelectMgr_Selection::*)() const) &SelectMgr_Selection::Mode, "returns the selection mode represented by this selection");
cls_SelectMgr_Selection.def("Entities", (const NCollection_Vector<opencascade::handle<SelectMgr_SensitiveEntity> > & (SelectMgr_Selection::*)() const) &SelectMgr_Selection::Entities, "Return entities.");
cls_SelectMgr_Selection.def("ChangeEntities", (NCollection_Vector<opencascade::handle<SelectMgr_SensitiveEntity> > & (SelectMgr_Selection::*)()) &SelectMgr_Selection::ChangeEntities, "Return entities.");
cls_SelectMgr_Selection.def("Init", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Init, "Begins an iteration scanning for sensitive primitives.");
cls_SelectMgr_Selection.def("More", (Standard_Boolean (SelectMgr_Selection::*)() const) &SelectMgr_Selection::More, "Continues the iteration scanning for sensitive primitives with the mode defined in this framework.");
cls_SelectMgr_Selection.def("Next", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Next, "Returns the next sensitive primitive found in the iteration. This is a scan for entities with the mode defined in this framework.");
cls_SelectMgr_Selection.def("Sensitive", (const opencascade::handle<SelectMgr_SensitiveEntity> & (SelectMgr_Selection::*)() const) &SelectMgr_Selection::Sensitive, "Returns any sensitive primitive in this framework.");
cls_SelectMgr_Selection.def("UpdateStatus", (SelectMgr_TypeOfUpdate (SelectMgr_Selection::*)() const) &SelectMgr_Selection::UpdateStatus, "Returns the flag UpdateFlag. This flage gives the update status of this framework in a ViewerSelector object: - full - partial, or - none.");
cls_SelectMgr_Selection.def("UpdateStatus", (void (SelectMgr_Selection::*)(const SelectMgr_TypeOfUpdate)) &SelectMgr_Selection::UpdateStatus, "None", py::arg("theStatus"));
cls_SelectMgr_Selection.def("UpdateBVHStatus", (void (SelectMgr_Selection::*)(const SelectMgr_TypeOfBVHUpdate)) &SelectMgr_Selection::UpdateBVHStatus, "None", py::arg("theStatus"));
cls_SelectMgr_Selection.def("BVHUpdateStatus", (SelectMgr_TypeOfBVHUpdate (SelectMgr_Selection::*)() const) &SelectMgr_Selection::BVHUpdateStatus, "None");
cls_SelectMgr_Selection.def("GetSelectionState", (SelectMgr_StateOfSelection (SelectMgr_Selection::*)() const) &SelectMgr_Selection::GetSelectionState, "Returns status of selection");
cls_SelectMgr_Selection.def("SetSelectionState", (void (SelectMgr_Selection::*)(const SelectMgr_StateOfSelection) const) &SelectMgr_Selection::SetSelectionState, "Sets status of selection", py::arg("theState"));
cls_SelectMgr_Selection.def("Sensitivity", (Standard_Integer (SelectMgr_Selection::*)() const) &SelectMgr_Selection::Sensitivity, "Returns sensitivity of the selection");
cls_SelectMgr_Selection.def("SetSensitivity", (void (SelectMgr_Selection::*)(const Standard_Integer)) &SelectMgr_Selection::SetSensitivity, "Changes sensitivity of the selection and all its entities to the given value. IMPORTANT: This method does not update any outer selection structures, so for proper updates use SelectMgr_SelectionManager::SetSelectionSensitivity method.", py::arg("theNewSens"));

// Enums

}