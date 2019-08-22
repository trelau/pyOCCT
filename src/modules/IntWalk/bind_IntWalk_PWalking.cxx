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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <gp_Dir.hxx>
#include <IntWalk_StatusDeflection.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <Standard_OutOfRange.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir2d.hxx>
#include <IntWalk_TheInt2S.hxx>
#include <IntWalk_PWalking.hxx>

void bind_IntWalk_PWalking(py::module &mod){

py::class_<IntWalk_PWalking> cls_IntWalk_PWalking(mod, "IntWalk_PWalking", "This class implements an algorithm to determine the intersection between 2 parametrized surfaces, marching from a starting point. The intersection line starts and ends on the natural surface's boundaries .");

// Constructors
cls_IntWalk_PWalking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Caro1"), py::arg("Caro2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntWalk_PWalking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Caro1"), py::arg("Caro2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

// Fields

// Methods
// cls_IntWalk_PWalking.def_static("operator new_", (void * (*)(size_t)) &IntWalk_PWalking::operator new, "None", py::arg("theSize"));
// cls_IntWalk_PWalking.def_static("operator delete_", (void (*)(void *)) &IntWalk_PWalking::operator delete, "None", py::arg("theAddress"));
// cls_IntWalk_PWalking.def_static("operator new[]_", (void * (*)(size_t)) &IntWalk_PWalking::operator new[], "None", py::arg("theSize"));
// cls_IntWalk_PWalking.def_static("operator delete[]_", (void (*)(void *)) &IntWalk_PWalking::operator delete[], "None", py::arg("theAddress"));
// cls_IntWalk_PWalking.def_static("operator new_", (void * (*)(size_t, void *)) &IntWalk_PWalking::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntWalk_PWalking.def_static("operator delete_", (void (*)(void *, void *)) &IntWalk_PWalking::operator delete, "None", py::arg(""), py::arg(""));
cls_IntWalk_PWalking.def("Perform", (void (IntWalk_PWalking::*)(const TColStd_Array1OfReal &)) &IntWalk_PWalking::Perform, "calculate the line of intersection", py::arg("ParDep"));
cls_IntWalk_PWalking.def("Perform", (void (IntWalk_PWalking::*)(const TColStd_Array1OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntWalk_PWalking::Perform, "calculate the line of intersection. The regulation of steps is done using min and max values on u and v. (if this data is not presented as in the previous method, the initial steps are calculated starting from min and max uv of faces).", py::arg("ParDep"), py::arg("u1min"), py::arg("v1min"), py::arg("u2min"), py::arg("v2min"), py::arg("u1max"), py::arg("v1max"), py::arg("u2max"), py::arg("v2max"));
cls_IntWalk_PWalking.def("PerformFirstPoint", (Standard_Boolean (IntWalk_PWalking::*)(const TColStd_Array1OfReal &, IntSurf_PntOn2S &)) &IntWalk_PWalking::PerformFirstPoint, "calculate the first point of a line of intersection", py::arg("ParDep"), py::arg("FirstPoint"));
cls_IntWalk_PWalking.def("IsDone", (Standard_Boolean (IntWalk_PWalking::*)() const) &IntWalk_PWalking::IsDone, "Returns true if the calculus was successful.");
cls_IntWalk_PWalking.def("NbPoints", (Standard_Integer (IntWalk_PWalking::*)() const) &IntWalk_PWalking::NbPoints, "Returns the number of points of the resulting polyline. An exception is raised if IsDone returns False.");
cls_IntWalk_PWalking.def("Value", (const IntSurf_PntOn2S & (IntWalk_PWalking::*)(const Standard_Integer) const) &IntWalk_PWalking::Value, "Returns the point of range Index on the polyline. An exception is raised if IsDone returns False. An exception is raised if Index<=0 or Index>NbPoints.", py::arg("Index"));
cls_IntWalk_PWalking.def("Line", (const opencascade::handle<IntSurf_LineOn2S> & (IntWalk_PWalking::*)() const) &IntWalk_PWalking::Line, "None");
cls_IntWalk_PWalking.def("TangentAtFirst", (Standard_Boolean (IntWalk_PWalking::*)() const) &IntWalk_PWalking::TangentAtFirst, "Returns True if the surface are tangent at the first point of the line. An exception is raised if IsDone returns False.");
cls_IntWalk_PWalking.def("TangentAtLast", (Standard_Boolean (IntWalk_PWalking::*)() const) &IntWalk_PWalking::TangentAtLast, "Returns true if the surface are tangent at the last point of the line. An exception is raised if IsDone returns False.");
cls_IntWalk_PWalking.def("IsClosed", (Standard_Boolean (IntWalk_PWalking::*)() const) &IntWalk_PWalking::IsClosed, "Returns True if the line is closed. An exception is raised if IsDone returns False.");
cls_IntWalk_PWalking.def("TangentAtLine", [](IntWalk_PWalking &self, Standard_Integer & Index){ const gp_Dir & rv = self.TangentAtLine(Index); return std::tuple<const gp_Dir &, Standard_Integer &>(rv, Index); }, "None", py::arg("Index"));
cls_IntWalk_PWalking.def("TestDeflection", (IntWalk_StatusDeflection (IntWalk_PWalking::*)(const IntImp_ConstIsoparametric)) &IntWalk_PWalking::TestDeflection, "None", py::arg("ChoixIso"));
cls_IntWalk_PWalking.def("TestArret", (Standard_Boolean (IntWalk_PWalking::*)(const Standard_Boolean, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &IntWalk_PWalking::TestArret, "None", py::arg("DejaReparti"), py::arg("Param"), py::arg("ChoixIso"));
cls_IntWalk_PWalking.def("RepartirOuDiviser", [](IntWalk_PWalking &self, Standard_Boolean & DejaReparti, IntImp_ConstIsoparametric & ChoixIso, Standard_Boolean & Arrive){ self.RepartirOuDiviser(DejaReparti, ChoixIso, Arrive); return std::tuple<Standard_Boolean &, Standard_Boolean &>(DejaReparti, Arrive); }, "None", py::arg("DejaReparti"), py::arg("ChoixIso"), py::arg("Arrive"));
cls_IntWalk_PWalking.def("AddAPoint", (void (IntWalk_PWalking::*)(const IntSurf_PntOn2S &)) &IntWalk_PWalking::AddAPoint, "Inserts thePOn2S in the end of line", py::arg("thePOn2S"));
cls_IntWalk_PWalking.def("RemoveAPoint", (void (IntWalk_PWalking::*)(const Standard_Integer)) &IntWalk_PWalking::RemoveAPoint, "Removes point with index theIndex from line. If theIndex is greater than the number of points in line then the last point will be removed. theIndex must be started with 1.", py::arg("theIndex"));
cls_IntWalk_PWalking.def("PutToBoundary", (Standard_Boolean (IntWalk_PWalking::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &)) &IntWalk_PWalking::PutToBoundary, "None", py::arg("theASurf1"), py::arg("theASurf2"));
cls_IntWalk_PWalking.def("SeekAdditionalPoints", (Standard_Boolean (IntWalk_PWalking::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer)) &IntWalk_PWalking::SeekAdditionalPoints, "None", py::arg("theASurf1"), py::arg("theASurf2"), py::arg("theMinNbPoints"));
cls_IntWalk_PWalking.def("MaxStep", (Standard_Real (IntWalk_PWalking::*)(Standard_Integer)) &IntWalk_PWalking::MaxStep, "None", py::arg("theIndex"));

// Enums

}