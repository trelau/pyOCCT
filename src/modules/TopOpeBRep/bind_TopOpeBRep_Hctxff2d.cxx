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
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_Hctxff2d.hxx>
#include <Standard_Type.hxx>
#include <GeomAbs_SurfaceType.hxx>

void bind_TopOpeBRep_Hctxff2d(py::module &mod){

py::class_<TopOpeBRep_Hctxff2d, opencascade::handle<TopOpeBRep_Hctxff2d>, Standard_Transient> cls_TopOpeBRep_Hctxff2d(mod, "TopOpeBRep_Hctxff2d", "None");

// Constructors
cls_TopOpeBRep_Hctxff2d.def(py::init<>());

// Fields

// Methods
cls_TopOpeBRep_Hctxff2d.def("SetFaces", (void (TopOpeBRep_Hctxff2d::*)(const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRep_Hctxff2d::SetFaces, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRep_Hctxff2d.def("SetHSurfaces", (void (TopOpeBRep_Hctxff2d::*)(const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HSurface> &)) &TopOpeBRep_Hctxff2d::SetHSurfaces, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRep_Hctxff2d.def("SetTolerances", (void (TopOpeBRep_Hctxff2d::*)(const Standard_Real, const Standard_Real)) &TopOpeBRep_Hctxff2d::SetTolerances, "None", py::arg("Tol1"), py::arg("Tol2"));
cls_TopOpeBRep_Hctxff2d.def("GetTolerances", [](TopOpeBRep_Hctxff2d &self, Standard_Real & Tol1, Standard_Real & Tol2){ self.GetTolerances(Tol1, Tol2); return std::tuple<Standard_Real &, Standard_Real &>(Tol1, Tol2); }, "None", py::arg("Tol1"), py::arg("Tol2"));
cls_TopOpeBRep_Hctxff2d.def("GetMaxTolerance", (Standard_Real (TopOpeBRep_Hctxff2d::*)() const) &TopOpeBRep_Hctxff2d::GetMaxTolerance, "None");
cls_TopOpeBRep_Hctxff2d.def("Face", (const TopoDS_Face & (TopOpeBRep_Hctxff2d::*)(const Standard_Integer) const) &TopOpeBRep_Hctxff2d::Face, "None", py::arg("I"));
cls_TopOpeBRep_Hctxff2d.def("HSurface", (opencascade::handle<BRepAdaptor_HSurface> (TopOpeBRep_Hctxff2d::*)(const Standard_Integer) const) &TopOpeBRep_Hctxff2d::HSurface, "None", py::arg("I"));
cls_TopOpeBRep_Hctxff2d.def("SurfacesSameOriented", (Standard_Boolean (TopOpeBRep_Hctxff2d::*)() const) &TopOpeBRep_Hctxff2d::SurfacesSameOriented, "None");
cls_TopOpeBRep_Hctxff2d.def("FacesSameOriented", (Standard_Boolean (TopOpeBRep_Hctxff2d::*)() const) &TopOpeBRep_Hctxff2d::FacesSameOriented, "None");
cls_TopOpeBRep_Hctxff2d.def("FaceSameOrientedWithRef", (Standard_Boolean (TopOpeBRep_Hctxff2d::*)(const Standard_Integer) const) &TopOpeBRep_Hctxff2d::FaceSameOrientedWithRef, "None", py::arg("I"));
cls_TopOpeBRep_Hctxff2d.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_Hctxff2d::get_type_name, "None");
cls_TopOpeBRep_Hctxff2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_Hctxff2d::get_type_descriptor, "None");
cls_TopOpeBRep_Hctxff2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_Hctxff2d::*)() const) &TopOpeBRep_Hctxff2d::DynamicType, "None");

// Enums

}