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
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Plate_D1.hxx>
#include <Plate_D2.hxx>
#include <Plate_D3.hxx>
#include <Standard_Handle.hxx>
#include <NLPlate_HGPPConstraint.hxx>
#include <Standard_Type.hxx>
#include <NLPlate_HPG0Constraint.hxx>
#include <NLPlate_HPG0G1Constraint.hxx>
#include <NLPlate_HPG0G2Constraint.hxx>
#include <NLPlate_HPG0G3Constraint.hxx>
#include <NLPlate_HPG1Constraint.hxx>
#include <NLPlate_HPG2Constraint.hxx>
#include <NLPlate_HPG3Constraint.hxx>
#include <NCollection_List.hxx>
#include <Plate_Plate.hxx>
#include <NLPlate_StackOfPlate.hxx>
#include <NCollection_Sequence.hxx>
#include <NLPlate_SequenceOfHGPPConstraint.hxx>
#include <Standard.hxx>
#include <Geom_Surface.hxx>
#include <NLPlate_NLPlate.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(NLPlate, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Plate");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");

// CLASS: NLPLATE_HGPPCONSTRAINT
py::class_<NLPlate_HGPPConstraint, opencascade::handle<NLPlate_HGPPConstraint>, Standard_Transient> cls_NLPlate_HGPPConstraint(mod, "NLPlate_HGPPConstraint", "define a PinPoint geometric Constraint used to load a Non Linear Plate");

// Methods
cls_NLPlate_HGPPConstraint.def("SetUVFreeSliding", (void (NLPlate_HGPPConstraint::*)(const Standard_Boolean)) &NLPlate_HGPPConstraint::SetUVFreeSliding, "None", py::arg("UVFree"));
cls_NLPlate_HGPPConstraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HGPPConstraint::*)(const Standard_Boolean)) &NLPlate_HGPPConstraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
cls_NLPlate_HGPPConstraint.def("SetActiveOrder", (void (NLPlate_HGPPConstraint::*)(const Standard_Integer)) &NLPlate_HGPPConstraint::SetActiveOrder, "None", py::arg("ActiveOrder"));
cls_NLPlate_HGPPConstraint.def("SetUV", (void (NLPlate_HGPPConstraint::*)(const gp_XY &)) &NLPlate_HGPPConstraint::SetUV, "None", py::arg("UV"));
cls_NLPlate_HGPPConstraint.def("SetOrientation", [](NLPlate_HGPPConstraint &self) -> void { return self.SetOrientation(); });
cls_NLPlate_HGPPConstraint.def("SetOrientation", (void (NLPlate_HGPPConstraint::*)(const Standard_Integer)) &NLPlate_HGPPConstraint::SetOrientation, "None", py::arg("Orient"));
cls_NLPlate_HGPPConstraint.def("SetG0Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG0Criterion, "None", py::arg("TolDist"));
cls_NLPlate_HGPPConstraint.def("SetG1Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG1Criterion, "None", py::arg("TolAng"));
cls_NLPlate_HGPPConstraint.def("SetG2Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG2Criterion, "None", py::arg("TolCurv"));
cls_NLPlate_HGPPConstraint.def("SetG3Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG3Criterion, "None", py::arg("TolG3"));
cls_NLPlate_HGPPConstraint.def("UVFreeSliding", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::UVFreeSliding, "None");
cls_NLPlate_HGPPConstraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::IncrementalLoadAllowed, "None");
cls_NLPlate_HGPPConstraint.def("ActiveOrder", (Standard_Integer (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::ActiveOrder, "None");
cls_NLPlate_HGPPConstraint.def("UV", (const gp_XY & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::UV, "None");
cls_NLPlate_HGPPConstraint.def("Orientation", (Standard_Integer (NLPlate_HGPPConstraint::*)()) &NLPlate_HGPPConstraint::Orientation, "None");
cls_NLPlate_HGPPConstraint.def("IsG0", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::IsG0, "None");
cls_NLPlate_HGPPConstraint.def("G0Target", (const gp_XYZ & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G0Target, "None");
cls_NLPlate_HGPPConstraint.def("G1Target", (const Plate_D1 & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G1Target, "None");
cls_NLPlate_HGPPConstraint.def("G2Target", (const Plate_D2 & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G2Target, "None");
cls_NLPlate_HGPPConstraint.def("G3Target", (const Plate_D3 & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G3Target, "None");
cls_NLPlate_HGPPConstraint.def("G0Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G0Criterion, "None");
cls_NLPlate_HGPPConstraint.def("G1Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G1Criterion, "None");
cls_NLPlate_HGPPConstraint.def("G2Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G2Criterion, "None");
cls_NLPlate_HGPPConstraint.def("G3Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G3Criterion, "None");
cls_NLPlate_HGPPConstraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HGPPConstraint::get_type_name, "None");
cls_NLPlate_HGPPConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HGPPConstraint::get_type_descriptor, "None");
cls_NLPlate_HGPPConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::DynamicType, "None");

// CLASS: NLPLATE_HPG0CONSTRAINT
py::class_<NLPlate_HPG0Constraint, opencascade::handle<NLPlate_HPG0Constraint>, NLPlate_HGPPConstraint> cls_NLPlate_HPG0Constraint(mod, "NLPlate_HPG0Constraint", "define a PinPoint G0 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG0Constraint.def(py::init<const gp_XY &, const gp_XYZ &>(), py::arg("UV"), py::arg("Value"));

// Methods
cls_NLPlate_HPG0Constraint.def("SetUVFreeSliding", (void (NLPlate_HPG0Constraint::*)(const Standard_Boolean)) &NLPlate_HPG0Constraint::SetUVFreeSliding, "None", py::arg("UVFree"));
cls_NLPlate_HPG0Constraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HPG0Constraint::*)(const Standard_Boolean)) &NLPlate_HPG0Constraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
cls_NLPlate_HPG0Constraint.def("UVFreeSliding", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::UVFreeSliding, "None");
cls_NLPlate_HPG0Constraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::IncrementalLoadAllowed, "None");
cls_NLPlate_HPG0Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::ActiveOrder, "None");
cls_NLPlate_HPG0Constraint.def("IsG0", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::IsG0, "None");
cls_NLPlate_HPG0Constraint.def("G0Target", (const gp_XYZ & (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::G0Target, "None");
cls_NLPlate_HPG0Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0Constraint::get_type_name, "None");
cls_NLPlate_HPG0Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG0Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0Constraint::*)() const) &NLPlate_HPG0Constraint::DynamicType, "None");

// CLASS: NLPLATE_HPG0G1CONSTRAINT
py::class_<NLPlate_HPG0G1Constraint, opencascade::handle<NLPlate_HPG0G1Constraint>, NLPlate_HPG0Constraint> cls_NLPlate_HPG0G1Constraint(mod, "NLPlate_HPG0G1Constraint", "define a PinPoint G0+G1 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG0G1Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"));

// Methods
cls_NLPlate_HPG0G1Constraint.def("SetOrientation", [](NLPlate_HPG0G1Constraint &self) -> void { return self.SetOrientation(); });
cls_NLPlate_HPG0G1Constraint.def("SetOrientation", (void (NLPlate_HPG0G1Constraint::*)(const Standard_Integer)) &NLPlate_HPG0G1Constraint::SetOrientation, "None", py::arg("Orient"));
cls_NLPlate_HPG0G1Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G1Constraint::*)() const) &NLPlate_HPG0G1Constraint::ActiveOrder, "None");
cls_NLPlate_HPG0G1Constraint.def("Orientation", (Standard_Integer (NLPlate_HPG0G1Constraint::*)()) &NLPlate_HPG0G1Constraint::Orientation, "None");
cls_NLPlate_HPG0G1Constraint.def("G1Target", (const Plate_D1 & (NLPlate_HPG0G1Constraint::*)() const) &NLPlate_HPG0G1Constraint::G1Target, "None");
cls_NLPlate_HPG0G1Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G1Constraint::get_type_name, "None");
cls_NLPlate_HPG0G1Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G1Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG0G1Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G1Constraint::*)() const) &NLPlate_HPG0G1Constraint::DynamicType, "None");

// CLASS: NLPLATE_HPG0G2CONSTRAINT
py::class_<NLPlate_HPG0G2Constraint, opencascade::handle<NLPlate_HPG0G2Constraint>, NLPlate_HPG0G1Constraint> cls_NLPlate_HPG0G2Constraint(mod, "NLPlate_HPG0G2Constraint", "define a PinPoint G0+G2 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG0G2Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &, const Plate_D2 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"), py::arg("D2T"));

// Methods
cls_NLPlate_HPG0G2Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G2Constraint::*)() const) &NLPlate_HPG0G2Constraint::ActiveOrder, "None");
cls_NLPlate_HPG0G2Constraint.def("G2Target", (const Plate_D2 & (NLPlate_HPG0G2Constraint::*)() const) &NLPlate_HPG0G2Constraint::G2Target, "None");
cls_NLPlate_HPG0G2Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G2Constraint::get_type_name, "None");
cls_NLPlate_HPG0G2Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G2Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG0G2Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G2Constraint::*)() const) &NLPlate_HPG0G2Constraint::DynamicType, "None");

// CLASS: NLPLATE_HPG0G3CONSTRAINT
py::class_<NLPlate_HPG0G3Constraint, opencascade::handle<NLPlate_HPG0G3Constraint>, NLPlate_HPG0G2Constraint> cls_NLPlate_HPG0G3Constraint(mod, "NLPlate_HPG0G3Constraint", "define a PinPoint G0+G3 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG0G3Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &, const Plate_D2 &, const Plate_D3 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"), py::arg("D2T"), py::arg("D3T"));

// Methods
cls_NLPlate_HPG0G3Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G3Constraint::*)() const) &NLPlate_HPG0G3Constraint::ActiveOrder, "None");
cls_NLPlate_HPG0G3Constraint.def("G3Target", (const Plate_D3 & (NLPlate_HPG0G3Constraint::*)() const) &NLPlate_HPG0G3Constraint::G3Target, "None");
cls_NLPlate_HPG0G3Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G3Constraint::get_type_name, "None");
cls_NLPlate_HPG0G3Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G3Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG0G3Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G3Constraint::*)() const) &NLPlate_HPG0G3Constraint::DynamicType, "None");

// CLASS: NLPLATE_HPG1CONSTRAINT
py::class_<NLPlate_HPG1Constraint, opencascade::handle<NLPlate_HPG1Constraint>, NLPlate_HGPPConstraint> cls_NLPlate_HPG1Constraint(mod, "NLPlate_HPG1Constraint", "define a PinPoint (no G0) G1 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG1Constraint.def(py::init<const gp_XY &, const Plate_D1 &>(), py::arg("UV"), py::arg("D1T"));

// Methods
cls_NLPlate_HPG1Constraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HPG1Constraint::*)(const Standard_Boolean)) &NLPlate_HPG1Constraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
cls_NLPlate_HPG1Constraint.def("SetOrientation", [](NLPlate_HPG1Constraint &self) -> void { return self.SetOrientation(); });
cls_NLPlate_HPG1Constraint.def("SetOrientation", (void (NLPlate_HPG1Constraint::*)(const Standard_Integer)) &NLPlate_HPG1Constraint::SetOrientation, "None", py::arg("Orient"));
cls_NLPlate_HPG1Constraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::IncrementalLoadAllowed, "None");
cls_NLPlate_HPG1Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::ActiveOrder, "None");
cls_NLPlate_HPG1Constraint.def("IsG0", (Standard_Boolean (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::IsG0, "None");
cls_NLPlate_HPG1Constraint.def("Orientation", (Standard_Integer (NLPlate_HPG1Constraint::*)()) &NLPlate_HPG1Constraint::Orientation, "None");
cls_NLPlate_HPG1Constraint.def("G1Target", (const Plate_D1 & (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::G1Target, "None");
cls_NLPlate_HPG1Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG1Constraint::get_type_name, "None");
cls_NLPlate_HPG1Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG1Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG1Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG1Constraint::*)() const) &NLPlate_HPG1Constraint::DynamicType, "None");

// CLASS: NLPLATE_HPG2CONSTRAINT
py::class_<NLPlate_HPG2Constraint, opencascade::handle<NLPlate_HPG2Constraint>, NLPlate_HPG1Constraint> cls_NLPlate_HPG2Constraint(mod, "NLPlate_HPG2Constraint", "define a PinPoint (no G0) G2 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG2Constraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D2 &>(), py::arg("UV"), py::arg("D1T"), py::arg("D2T"));

// Methods
cls_NLPlate_HPG2Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG2Constraint::*)() const) &NLPlate_HPG2Constraint::ActiveOrder, "None");
cls_NLPlate_HPG2Constraint.def("G2Target", (const Plate_D2 & (NLPlate_HPG2Constraint::*)() const) &NLPlate_HPG2Constraint::G2Target, "None");
cls_NLPlate_HPG2Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG2Constraint::get_type_name, "None");
cls_NLPlate_HPG2Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG2Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG2Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG2Constraint::*)() const) &NLPlate_HPG2Constraint::DynamicType, "None");

// CLASS: NLPLATE_HPG3CONSTRAINT
py::class_<NLPlate_HPG3Constraint, opencascade::handle<NLPlate_HPG3Constraint>, NLPlate_HPG2Constraint> cls_NLPlate_HPG3Constraint(mod, "NLPlate_HPG3Constraint", "define a PinPoint (no G0) G3 Constraint used to load a Non Linear Plate");

// Constructors
cls_NLPlate_HPG3Constraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D2 &, const Plate_D3 &>(), py::arg("UV"), py::arg("D1T"), py::arg("D2T"), py::arg("D3T"));

// Methods
cls_NLPlate_HPG3Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG3Constraint::*)() const) &NLPlate_HPG3Constraint::ActiveOrder, "None");
cls_NLPlate_HPG3Constraint.def("G3Target", (const Plate_D3 & (NLPlate_HPG3Constraint::*)() const) &NLPlate_HPG3Constraint::G3Target, "None");
cls_NLPlate_HPG3Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG3Constraint::get_type_name, "None");
cls_NLPlate_HPG3Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG3Constraint::get_type_descriptor, "None");
cls_NLPlate_HPG3Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG3Constraint::*)() const) &NLPlate_HPG3Constraint::DynamicType, "None");

// TYPEDEF: NLPLATE_STACKOFPLATE
bind_NCollection_List<Plate_Plate>(mod, "NLPlate_StackOfPlate", py::module_local(false));

// TYPEDEF: NLPLATE_LISTITERATOROFSTACKOFPLATE
bind_NCollection_TListIterator<Plate_Plate>(mod, "NLPlate_ListIteratorOfStackOfPlate", py::module_local(false));

// TYPEDEF: NLPLATE_SEQUENCEOFHGPPCONSTRAINT
bind_NCollection_Sequence<opencascade::handle<NLPlate_HGPPConstraint> >(mod, "NLPlate_SequenceOfHGPPConstraint", py::module_local(false));

// CLASS: NLPLATE_NLPLATE
py::class_<NLPlate_NLPlate> cls_NLPlate_NLPlate(mod, "NLPlate_NLPlate", "None");

// Constructors
cls_NLPlate_NLPlate.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("InitialSurface"));

// Methods
// cls_NLPlate_NLPlate.def_static("operator new_", (void * (*)(size_t)) &NLPlate_NLPlate::operator new, "None", py::arg("theSize"));
// cls_NLPlate_NLPlate.def_static("operator delete_", (void (*)(void *)) &NLPlate_NLPlate::operator delete, "None", py::arg("theAddress"));
// cls_NLPlate_NLPlate.def_static("operator new[]_", (void * (*)(size_t)) &NLPlate_NLPlate::operator new[], "None", py::arg("theSize"));
// cls_NLPlate_NLPlate.def_static("operator delete[]_", (void (*)(void *)) &NLPlate_NLPlate::operator delete[], "None", py::arg("theAddress"));
// cls_NLPlate_NLPlate.def_static("operator new_", (void * (*)(size_t, void *)) &NLPlate_NLPlate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_NLPlate_NLPlate.def_static("operator delete_", (void (*)(void *, void *)) &NLPlate_NLPlate::operator delete, "None", py::arg(""), py::arg(""));
cls_NLPlate_NLPlate.def("Load", (void (NLPlate_NLPlate::*)(const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_NLPlate::Load, "None", py::arg("GConst"));
cls_NLPlate_NLPlate.def("Solve", [](NLPlate_NLPlate &self) -> void { return self.Solve(); });
cls_NLPlate_NLPlate.def("Solve", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.Solve(a0); });
cls_NLPlate_NLPlate.def("Solve", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_NLPlate::Solve, "None", py::arg("ord"), py::arg("InitialConsraintOrder"));
cls_NLPlate_NLPlate.def("Solve2", [](NLPlate_NLPlate &self) -> void { return self.Solve2(); });
cls_NLPlate_NLPlate.def("Solve2", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.Solve2(a0); });
cls_NLPlate_NLPlate.def("Solve2", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_NLPlate::Solve2, "None", py::arg("ord"), py::arg("InitialConsraintOrder"));
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self) -> void { return self.IncrementalSolve(); });
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.IncrementalSolve(a0); });
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.IncrementalSolve(a0, a1); });
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.IncrementalSolve(a0, a1, a2); });
cls_NLPlate_NLPlate.def("IncrementalSolve", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &NLPlate_NLPlate::IncrementalSolve, "None", py::arg("ord"), py::arg("InitialConsraintOrder"), py::arg("NbIncrements"), py::arg("UVSliding"));
cls_NLPlate_NLPlate.def("IsDone", (Standard_Boolean (NLPlate_NLPlate::*)() const) &NLPlate_NLPlate::IsDone, "returns True if all has been correctly done.");
cls_NLPlate_NLPlate.def("destroy", (void (NLPlate_NLPlate::*)()) &NLPlate_NLPlate::destroy, "None");
cls_NLPlate_NLPlate.def("Init", (void (NLPlate_NLPlate::*)()) &NLPlate_NLPlate::Init, "reset the Plate in the initial state ( same as after Create((Surface))");
cls_NLPlate_NLPlate.def("Evaluate", (gp_XYZ (NLPlate_NLPlate::*)(const gp_XY &) const) &NLPlate_NLPlate::Evaluate, "None", py::arg("point2d"));
cls_NLPlate_NLPlate.def("EvaluateDerivative", (gp_XYZ (NLPlate_NLPlate::*)(const gp_XY &, const Standard_Integer, const Standard_Integer) const) &NLPlate_NLPlate::EvaluateDerivative, "None", py::arg("point2d"), py::arg("iu"), py::arg("iv"));
cls_NLPlate_NLPlate.def("Continuity", (Standard_Integer (NLPlate_NLPlate::*)() const) &NLPlate_NLPlate::Continuity, "None");
cls_NLPlate_NLPlate.def("ConstraintsSliding", [](NLPlate_NLPlate &self) -> void { return self.ConstraintsSliding(); });
cls_NLPlate_NLPlate.def("ConstraintsSliding", (void (NLPlate_NLPlate::*)(const Standard_Integer)) &NLPlate_NLPlate::ConstraintsSliding, "None", py::arg("NbIterations"));
cls_NLPlate_NLPlate.def("MaxActiveConstraintOrder", (Standard_Integer (NLPlate_NLPlate::*)() const) &NLPlate_NLPlate::MaxActiveConstraintOrder, "None");


}
