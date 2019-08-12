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
#include <gp_Pnt.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <IntSurf_InteriorPointTool.hxx>

void bind_IntSurf_InteriorPointTool(py::module &mod){

py::class_<IntSurf_InteriorPointTool, std::unique_ptr<IntSurf_InteriorPointTool, Deleter<IntSurf_InteriorPointTool>>> cls_IntSurf_InteriorPointTool(mod, "IntSurf_InteriorPointTool", "This class provides a tool on the 'interior point' that can be used to instantiates the Walking algorithmes (see package IntWalk).");

// Constructors

// Fields

// Methods
// cls_IntSurf_InteriorPointTool.def_static("operator new_", (void * (*)(size_t)) &IntSurf_InteriorPointTool::operator new, "None", py::arg("theSize"));
// cls_IntSurf_InteriorPointTool.def_static("operator delete_", (void (*)(void *)) &IntSurf_InteriorPointTool::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPointTool.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_InteriorPointTool::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_InteriorPointTool.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_InteriorPointTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPointTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_InteriorPointTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_InteriorPointTool.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_InteriorPointTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_InteriorPointTool.def_static("Value3d_", (gp_Pnt (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Value3d, "Returns the 3d coordinates of the starting point.", py::arg("PStart"));
cls_IntSurf_InteriorPointTool.def_static("Value2d_", [](const IntSurf_InteriorPoint & PStart, Standard_Real & U, Standard_Real & V){ IntSurf_InteriorPointTool::Value2d(PStart, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the <U,V> parameters which are associated with <P> it's the parameters which start the marching algorithm", py::arg("PStart"), py::arg("U"), py::arg("V"));
cls_IntSurf_InteriorPointTool.def_static("Direction3d_", (gp_Vec (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Direction3d, "returns the tangent at the intersectin in 3d space associated to <P>", py::arg("PStart"));
cls_IntSurf_InteriorPointTool.def_static("Direction2d_", (gp_Dir2d (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Direction2d, "returns the tangent at the intersectin in the parametric space of the parametrized surface.This tangent is associated to the value2d", py::arg("PStart"));

// Enums

}