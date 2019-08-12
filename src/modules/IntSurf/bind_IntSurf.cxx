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
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <IntSurf_Transition.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntSurf_Couple.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <IntSurf_Quadric.hxx>
#include <IntSurf_QuadricTool.hxx>
#include <IntSurf_PathPoint.hxx>
#include <IntSurf_PathPointTool.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <IntSurf_InteriorPointTool.hxx>
#include <IntSurf.hxx>

void bind_IntSurf(py::module &mod){

py::class_<IntSurf, std::unique_ptr<IntSurf, Deleter<IntSurf>>> cls_IntSurf(mod, "IntSurf", "This package provides resources for all the packages concerning the intersection between surfaces.");

// Constructors

// Fields

// Methods
// cls_IntSurf.def_static("operator new_", (void * (*)(size_t)) &IntSurf::operator new, "None", py::arg("theSize"));
// cls_IntSurf.def_static("operator delete_", (void (*)(void *)) &IntSurf::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf::operator new[], "None", py::arg("theSize"));
// cls_IntSurf.def_static("operator delete[]_", (void (*)(void *)) &IntSurf::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf.def_static("MakeTransition_", (void (*)(const gp_Vec &, const gp_Vec &, const gp_Dir &, IntSurf_Transition &, IntSurf_Transition &)) &IntSurf::MakeTransition, "Computes the transition of the intersection point between the two lines. TgFirst is the tangent vector of the first line. TgSecond is the tangent vector of the second line. Normal is the direction used to orientate the cross product TgFirst^TgSecond. TFirst is the transition of the point on the first line. TSecond is the transition of the point on the second line.", py::arg("TgFirst"), py::arg("TgSecond"), py::arg("Normal"), py::arg("TFirst"), py::arg("TSecond"));
// cls_IntSurf.def_static("SetPeriod_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, Standard_Real [4])) &IntSurf::SetPeriod, "Fills theArrOfPeriod array by the period values of theFirstSurf and theSecondSurf. [0] = U-period of theFirstSurf, [1] = V-period of theFirstSurf, [2] = U-period of theSecondSurf, [3] = V-period of theSecondSurf.", py::arg("theFirstSurf"), py::arg("theSecondSurf"), py::arg("theArrOfPeriod"));

// Enums

}