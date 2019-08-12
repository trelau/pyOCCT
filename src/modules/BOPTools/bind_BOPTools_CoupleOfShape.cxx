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
#include <TopoDS_Shape.hxx>
#include <BOPTools_CoupleOfShape.hxx>

void bind_BOPTools_CoupleOfShape(py::module &mod){

py::class_<BOPTools_CoupleOfShape, std::unique_ptr<BOPTools_CoupleOfShape, Deleter<BOPTools_CoupleOfShape>>> cls_BOPTools_CoupleOfShape(mod, "BOPTools_CoupleOfShape", "None");

// Constructors
cls_BOPTools_CoupleOfShape.def(py::init<>());

// Fields

// Methods
cls_BOPTools_CoupleOfShape.def("SetShape1", (void (BOPTools_CoupleOfShape::*)(const TopoDS_Shape &)) &BOPTools_CoupleOfShape::SetShape1, "None", py::arg("theShape"));
cls_BOPTools_CoupleOfShape.def("Shape1", (const TopoDS_Shape & (BOPTools_CoupleOfShape::*)() const) &BOPTools_CoupleOfShape::Shape1, "None");
cls_BOPTools_CoupleOfShape.def("SetShape2", (void (BOPTools_CoupleOfShape::*)(const TopoDS_Shape &)) &BOPTools_CoupleOfShape::SetShape2, "None", py::arg("theShape"));
cls_BOPTools_CoupleOfShape.def("Shape2", (const TopoDS_Shape & (BOPTools_CoupleOfShape::*)() const) &BOPTools_CoupleOfShape::Shape2, "None");

// Enums

}