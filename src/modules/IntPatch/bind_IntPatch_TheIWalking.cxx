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
#include <Standard_TypeDef.hxx>
#include <IntSurf_SequenceOfPathPoint.hxx>
#include <IntSurf_SequenceOfInteriorPoint.hxx>
#include <IntPatch_TheSurfFunction.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntPatch_TheIWLineOfTheIWalking.hxx>
#include <IntSurf_PathPoint.hxx>
#include <math_Vector.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <IntWalk_StatusDeflection.hxx>
#include <gp_Pnt2d.hxx>
#include <IntWalk_VectorOfWalkingData.hxx>
#include <IntWalk_VectorOfInteger.hxx>
#include <Bnd_Range.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <IntPatch_SequenceOfIWLineOfTheIWalking.hxx>
#include <IntPatch_TheIWalking.hxx>

void bind_IntPatch_TheIWalking(py::module &mod){

py::class_<IntPatch_TheIWalking, std::unique_ptr<IntPatch_TheIWalking, Deleter<IntPatch_TheIWalking>>> cls_IntPatch_TheIWalking(mod, "IntPatch_TheIWalking", "None");

// Constructors
cls_IntPatch_TheIWalking.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"));
cls_IntPatch_TheIWalking.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"), py::arg("theToFillHoles"));

// Fields

// Methods
// cls_IntPatch_TheIWalking.def_static("operator new_", (void * (*)(size_t)) &IntPatch_TheIWalking::operator new, "None", py::arg("theSize"));
// cls_IntPatch_TheIWalking.def_static("operator delete_", (void (*)(void *)) &IntPatch_TheIWalking::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_TheIWalking.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_TheIWalking::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_TheIWalking.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_TheIWalking::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_TheIWalking.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_TheIWalking::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_TheIWalking.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_TheIWalking::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_TheIWalking.def("SetTolerance", (void (IntPatch_TheIWalking::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_TheIWalking::SetTolerance, "Deflection is the maximum deflection admitted between two consecutive points on a resulting polyline. Step is the maximum increment admitted between two consecutive points (in 2d space). Epsilon is the tolerance beyond which 2 points are confused", py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"));
cls_IntPatch_TheIWalking.def("Perform", [](IntPatch_TheIWalking &self, const IntSurf_SequenceOfPathPoint & a0, const IntSurf_SequenceOfInteriorPoint & a1, IntPatch_TheSurfFunction & a2, const opencascade::handle<Adaptor3d_HSurface> & a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_IntPatch_TheIWalking.def("Perform", (void (IntPatch_TheIWalking::*)(const IntSurf_SequenceOfPathPoint &, const IntSurf_SequenceOfInteriorPoint &, IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean)) &IntPatch_TheIWalking::Perform, "Searches a set of polylines starting on a point of Pnts1 or Pnts2. Each point on a resulting polyline verifies F(u,v)=0", py::arg("Pnts1"), py::arg("Pnts2"), py::arg("Func"), py::arg("S"), py::arg("Reversed"));
cls_IntPatch_TheIWalking.def("Perform", [](IntPatch_TheIWalking &self, const IntSurf_SequenceOfPathPoint & a0, IntPatch_TheSurfFunction & a1, const opencascade::handle<Adaptor3d_HSurface> & a2) -> void { return self.Perform(a0, a1, a2); });
cls_IntPatch_TheIWalking.def("Perform", (void (IntPatch_TheIWalking::*)(const IntSurf_SequenceOfPathPoint &, IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean)) &IntPatch_TheIWalking::Perform, "Searches a set of polylines starting on a point of Pnts1. Each point on a resulting polyline verifies F(u,v)=0", py::arg("Pnts1"), py::arg("Func"), py::arg("S"), py::arg("Reversed"));
cls_IntPatch_TheIWalking.def("IsDone", (Standard_Boolean (IntPatch_TheIWalking::*)() const) &IntPatch_TheIWalking::IsDone, "Returns true if the calculus was successful.");
cls_IntPatch_TheIWalking.def("NbLines", (Standard_Integer (IntPatch_TheIWalking::*)() const) &IntPatch_TheIWalking::NbLines, "Returns the number of resulting polylines. An exception is raised if IsDone returns False.");
cls_IntPatch_TheIWalking.def("Value", (const opencascade::handle<IntPatch_TheIWLineOfTheIWalking> & (IntPatch_TheIWalking::*)(const Standard_Integer) const) &IntPatch_TheIWalking::Value, "Returns the polyline of range Index. An exception is raised if IsDone is False. An exception is raised if Index<=0 or Index>NbLines.", py::arg("Index"));
cls_IntPatch_TheIWalking.def("NbSinglePnts", (Standard_Integer (IntPatch_TheIWalking::*)() const) &IntPatch_TheIWalking::NbSinglePnts, "Returns the number of points belonging to Pnts on which no line starts or ends. An exception is raised if IsDone returns False.");
cls_IntPatch_TheIWalking.def("SinglePnt", (const IntSurf_PathPoint & (IntPatch_TheIWalking::*)(const Standard_Integer) const) &IntPatch_TheIWalking::SinglePnt, "Returns the point of range Index . An exception is raised if IsDone returns False. An exception is raised if Index<=0 or Index > NbSinglePnts.", py::arg("Index"));

// Enums

}