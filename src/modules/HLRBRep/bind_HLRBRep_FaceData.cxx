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
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <HLRAlgo_WiresBlock.hxx>
#include <HLRBRep_Surface.hxx>
#include <HLRBRep_FaceData.hxx>

void bind_HLRBRep_FaceData(py::module &mod){

py::class_<HLRBRep_FaceData, std::unique_ptr<HLRBRep_FaceData, Deleter<HLRBRep_FaceData>>> cls_HLRBRep_FaceData(mod, "HLRBRep_FaceData", "None");

// Constructors
cls_HLRBRep_FaceData.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_FaceData.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_FaceData::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_FaceData.def_static("operator delete_", (void (*)(void *)) &HLRBRep_FaceData::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_FaceData.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_FaceData::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_FaceData.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_FaceData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_FaceData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_FaceData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_FaceData.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_FaceData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_FaceData.def("Set", (void (HLRBRep_FaceData::*)(const TopoDS_Face &, const TopAbs_Orientation, const Standard_Boolean, const Standard_Integer)) &HLRBRep_FaceData::Set, "<Or> is the orientation of the face. <Cl> is true if the face belongs to a closed volume. <NW> is the number of wires ( or block of edges ) of the face.", py::arg("FG"), py::arg("Or"), py::arg("Cl"), py::arg("NW"));
cls_HLRBRep_FaceData.def("SetWire", (void (HLRBRep_FaceData::*)(const Standard_Integer, const Standard_Integer)) &HLRBRep_FaceData::SetWire, "Set <NE> the number of edges of the wire number <WI>.", py::arg("WI"), py::arg("NE"));
cls_HLRBRep_FaceData.def("SetWEdge", (void (HLRBRep_FaceData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const TopAbs_Orientation, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &HLRBRep_FaceData::SetWEdge, "Set the edge number <EWI> of the wire <WI>.", py::arg("WI"), py::arg("EWI"), py::arg("EI"), py::arg("Or"), py::arg("OutL"), py::arg("Inte"), py::arg("Dble"), py::arg("IsoL"));
cls_HLRBRep_FaceData.def("Selected", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Selected, "None");
cls_HLRBRep_FaceData.def("Selected", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Selected, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Back", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Back, "None");
cls_HLRBRep_FaceData.def("Back", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Back, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Side", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Side, "None");
cls_HLRBRep_FaceData.def("Side", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Side, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Closed", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Closed, "None");
cls_HLRBRep_FaceData.def("Closed", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Closed, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Hiding", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Hiding, "None");
cls_HLRBRep_FaceData.def("Hiding", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Hiding, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Simple", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Simple, "None");
cls_HLRBRep_FaceData.def("Simple", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Simple, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Cut", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Cut, "None");
cls_HLRBRep_FaceData.def("Cut", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Cut, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("WithOutL", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::WithOutL, "None");
cls_HLRBRep_FaceData.def("WithOutL", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::WithOutL, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Plane", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Plane, "None");
cls_HLRBRep_FaceData.def("Plane", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Plane, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Cylinder", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Cylinder, "None");
cls_HLRBRep_FaceData.def("Cylinder", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Cylinder, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Cone", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Cone, "None");
cls_HLRBRep_FaceData.def("Cone", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Cone, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Sphere", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Sphere, "None");
cls_HLRBRep_FaceData.def("Sphere", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Sphere, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Torus", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Torus, "None");
cls_HLRBRep_FaceData.def("Torus", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Torus, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Size", (Standard_Real (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Size, "None");
cls_HLRBRep_FaceData.def("Size", (void (HLRBRep_FaceData::*)(const Standard_Real)) &HLRBRep_FaceData::Size, "None", py::arg("S"));
cls_HLRBRep_FaceData.def("Orientation", (TopAbs_Orientation (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Orientation, "None");
cls_HLRBRep_FaceData.def("Orientation", (void (HLRBRep_FaceData::*)(const TopAbs_Orientation)) &HLRBRep_FaceData::Orientation, "None", py::arg("O"));
cls_HLRBRep_FaceData.def("Wires", (opencascade::handle<HLRAlgo_WiresBlock> & (HLRBRep_FaceData::*)()) &HLRBRep_FaceData::Wires, "None");
cls_HLRBRep_FaceData.def("Geometry", (HLRBRep_Surface & (HLRBRep_FaceData::*)()) &HLRBRep_FaceData::Geometry, "None");
cls_HLRBRep_FaceData.def("Tolerance", (Standard_ShortReal (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Tolerance, "None");

// Enums

}