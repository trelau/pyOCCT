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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGeom_RuledSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_RuledSurface(py::module &mod){

py::class_<IGESGeom_RuledSurface, opencascade::handle<IGESGeom_RuledSurface>, IGESData_IGESEntity> cls_IGESGeom_RuledSurface(mod, "IGESGeom_RuledSurface", "defines IGESRuledSurface, Type <118> Form <0-1> in package IGESGeom A ruled surface is formed by moving a line connecting points of equal relative arc length or equal relative parametric value on two parametric curves from a start point to a terminate point on the curves. The parametric curves may be points, lines, circles, conics, rational B-splines, parametric splines or any parametric curve defined in the IGES specification.");

// Constructors
cls_IGESGeom_RuledSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_RuledSurface.def("Init", (void (IGESGeom_RuledSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Integer)) &IGESGeom_RuledSurface::Init, "This method is used to set the fields of the class RuledSurface - aCurve : First parametric curve - anotherCurve : Second parametric curve - aDirFlag : Direction Flag 0 = Join first to first, last to last 1 = Join first to last, last to first - aDevFlag : Developable Surface Flag 1 = Developable 0 = Possibly not", py::arg("aCurve"), py::arg("anotherCurve"), py::arg("aDirFlag"), py::arg("aDevFlag"));
cls_IGESGeom_RuledSurface.def("SetRuledByParameter", (void (IGESGeom_RuledSurface::*)(const Standard_Boolean)) &IGESGeom_RuledSurface::SetRuledByParameter, "Sets <me> to be Ruled by Parameter (Form 1) if <mode> is True, or Ruled by Length (Form 0) else", py::arg("mode"));
cls_IGESGeom_RuledSurface.def("IsRuledByParameter", (Standard_Boolean (IGESGeom_RuledSurface::*)() const) &IGESGeom_RuledSurface::IsRuledByParameter, "Returns True if Form is 1");
cls_IGESGeom_RuledSurface.def("FirstCurve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_RuledSurface::*)() const) &IGESGeom_RuledSurface::FirstCurve, "returns the first curve");
cls_IGESGeom_RuledSurface.def("SecondCurve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_RuledSurface::*)() const) &IGESGeom_RuledSurface::SecondCurve, "returns the second curve");
cls_IGESGeom_RuledSurface.def("DirectionFlag", (Standard_Integer (IGESGeom_RuledSurface::*)() const) &IGESGeom_RuledSurface::DirectionFlag, "return the sense of direction 0 = Join first to first, last to last 1 = Join first to last, last to first");
cls_IGESGeom_RuledSurface.def("IsDevelopable", (Standard_Boolean (IGESGeom_RuledSurface::*)() const) &IGESGeom_RuledSurface::IsDevelopable, "returns True if developable else False");
cls_IGESGeom_RuledSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_RuledSurface::get_type_name, "None");
cls_IGESGeom_RuledSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_RuledSurface::get_type_descriptor, "None");
cls_IGESGeom_RuledSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_RuledSurface::*)() const) &IGESGeom_RuledSurface::DynamicType, "None");

// Enums

}