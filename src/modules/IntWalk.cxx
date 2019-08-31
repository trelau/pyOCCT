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
#include <IntWalk_StatusDeflection.hxx>
#include <Standard_TypeDef.hxx>
#include <IntWalk_VectorOfWalkingData.hxx>
#include <NCollection_StdAllocator.hxx>
#include <IntWalk_VectorOfInteger.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Vec.hxx>
#include <IntWalk_TheFunctionOfTheInt2S.hxx>
#include <math_FunctionSetRoot.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntWalk_TheInt2S.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Standard_OutOfRange.hxx>
#include <IntWalk_PWalking.hxx>

PYBIND11_MAKE_OPAQUE(std::vector<IntWalk_WalkingData, NCollection_StdAllocator<IntWalk_WalkingData> >)
PYBIND11_MAKE_OPAQUE(std::vector<int, NCollection_StdAllocator<int> >)

PYBIND11_MODULE(IntWalk, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.math");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.IntImp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.IntSurf");

// ENUM: INTWALK_STATUSDEFLECTION
py::enum_<IntWalk_StatusDeflection>(mod, "IntWalk_StatusDeflection", "None")
	.value("IntWalk_PasTropGrand", IntWalk_StatusDeflection::IntWalk_PasTropGrand)
	.value("IntWalk_StepTooSmall", IntWalk_StatusDeflection::IntWalk_StepTooSmall)
	.value("IntWalk_PointConfondu", IntWalk_StatusDeflection::IntWalk_PointConfondu)
	.value("IntWalk_ArretSurPointPrecedent", IntWalk_StatusDeflection::IntWalk_ArretSurPointPrecedent)
	.value("IntWalk_ArretSurPoint", IntWalk_StatusDeflection::IntWalk_ArretSurPoint)
	.value("IntWalk_OK", IntWalk_StatusDeflection::IntWalk_OK)
	.export_values();


// CLASS: INTWALK_WALKINGDATA
py::class_<IntWalk_WalkingData> cls_IntWalk_WalkingData(mod, "IntWalk_WalkingData", "None");

// Fields
cls_IntWalk_WalkingData.def_readwrite("ustart", &IntWalk_WalkingData::ustart, "None");
cls_IntWalk_WalkingData.def_readwrite("vstart", &IntWalk_WalkingData::vstart, "None");
cls_IntWalk_WalkingData.def_readwrite("etat", &IntWalk_WalkingData::etat, "None");

// TYPEDEF: INTWALK_VECTOROFWALKINGDATA
py::bind_vector<std::vector<IntWalk_WalkingData, NCollection_StdAllocator<IntWalk_WalkingData> >>(mod, "IntWalk_VectorOfWalkingData");

// TYPEDEF: INTWALK_VECTOROFINTEGER
py::bind_vector<std::vector<int, NCollection_StdAllocator<int> >>(mod, "IntWalk_VectorOfInteger");

// CLASS: INTWALK_THEFUNCTIONOFTHEINT2S
py::class_<IntWalk_TheFunctionOfTheInt2S, math_FunctionSetWithDerivatives> cls_IntWalk_TheFunctionOfTheInt2S(mod, "IntWalk_TheFunctionOfTheInt2S", "None");

// Constructors
cls_IntWalk_TheFunctionOfTheInt2S.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("S2"));

// Methods
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator new_", (void * (*)(size_t)) &IntWalk_TheFunctionOfTheInt2S::operator new, "None", py::arg("theSize"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator delete_", (void (*)(void *)) &IntWalk_TheFunctionOfTheInt2S::operator delete, "None", py::arg("theAddress"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator new[]_", (void * (*)(size_t)) &IntWalk_TheFunctionOfTheInt2S::operator new[], "None", py::arg("theSize"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator delete[]_", (void (*)(void *)) &IntWalk_TheFunctionOfTheInt2S::operator delete[], "None", py::arg("theAddress"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator new_", (void * (*)(size_t, void *)) &IntWalk_TheFunctionOfTheInt2S::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntWalk_TheFunctionOfTheInt2S.def_static("operator delete_", (void (*)(void *, void *)) &IntWalk_TheFunctionOfTheInt2S::operator delete, "None", py::arg(""), py::arg(""));
cls_IntWalk_TheFunctionOfTheInt2S.def("NbVariables", (Standard_Integer (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::NbVariables, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("NbEquations", (Standard_Integer (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::NbEquations, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("Value", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Vector &)) &IntWalk_TheFunctionOfTheInt2S::Value, "None", py::arg("X"), py::arg("F"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Derivatives", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Matrix &)) &IntWalk_TheFunctionOfTheInt2S::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Values", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntWalk_TheFunctionOfTheInt2S::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntWalk_TheFunctionOfTheInt2S.def("ComputeParameters", (void (IntWalk_TheFunctionOfTheInt2S::*)(const IntImp_ConstIsoparametric, const TColStd_Array1OfReal &, math_Vector &, math_Vector &, math_Vector &, math_Vector &)) &IntWalk_TheFunctionOfTheInt2S::ComputeParameters, "None", py::arg("ChoixIso"), py::arg("Param"), py::arg("UVap"), py::arg("BornInf"), py::arg("BornSup"), py::arg("Tolerance"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Root", (Standard_Real (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::Root, "returns somme des fi*fi");
cls_IntWalk_TheFunctionOfTheInt2S.def("Point", (gp_Pnt (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::Point, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("IsTangent", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &IntWalk_TheFunctionOfTheInt2S::IsTangent, "None", py::arg("UVap"), py::arg("Param"), py::arg("BestChoix"));
cls_IntWalk_TheFunctionOfTheInt2S.def("Direction", (gp_Dir (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::Direction, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("DirectionOnS1", (gp_Dir2d (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::DirectionOnS1, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("DirectionOnS2", (gp_Dir2d (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::DirectionOnS2, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("AuxillarSurface1", (const opencascade::handle<Adaptor3d_HSurface> & (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::AuxillarSurface1, "None");
cls_IntWalk_TheFunctionOfTheInt2S.def("AuxillarSurface2", (const opencascade::handle<Adaptor3d_HSurface> & (IntWalk_TheFunctionOfTheInt2S::*)() const) &IntWalk_TheFunctionOfTheInt2S::AuxillarSurface2, "None");

// CLASS: INTWALK_THEINT2S
py::class_<IntWalk_TheInt2S> cls_IntWalk_TheInt2S(mod, "IntWalk_TheInt2S", "None");

// Constructors
cls_IntWalk_TheInt2S.def(py::init<const TColStd_Array1OfReal &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Param"), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));
cls_IntWalk_TheInt2S.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));

// Methods
// cls_IntWalk_TheInt2S.def_static("operator new_", (void * (*)(size_t)) &IntWalk_TheInt2S::operator new, "None", py::arg("theSize"));
// cls_IntWalk_TheInt2S.def_static("operator delete_", (void (*)(void *)) &IntWalk_TheInt2S::operator delete, "None", py::arg("theAddress"));
// cls_IntWalk_TheInt2S.def_static("operator new[]_", (void * (*)(size_t)) &IntWalk_TheInt2S::operator new[], "None", py::arg("theSize"));
// cls_IntWalk_TheInt2S.def_static("operator delete[]_", (void (*)(void *)) &IntWalk_TheInt2S::operator delete[], "None", py::arg("theAddress"));
// cls_IntWalk_TheInt2S.def_static("operator new_", (void * (*)(size_t, void *)) &IntWalk_TheInt2S::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntWalk_TheInt2S.def_static("operator delete_", (void (*)(void *, void *)) &IntWalk_TheInt2S::operator delete, "None", py::arg(""), py::arg(""));
cls_IntWalk_TheInt2S.def("Perform", (IntImp_ConstIsoparametric (IntWalk_TheInt2S::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &)) &IntWalk_TheInt2S::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is calculated)", py::arg("Param"), py::arg("Rsnld"));
cls_IntWalk_TheInt2S.def("Perform", (IntImp_ConstIsoparametric (IntWalk_TheInt2S::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &, const IntImp_ConstIsoparametric)) &IntWalk_TheInt2S::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is given by ChoixIso)", py::arg("Param"), py::arg("Rsnld"), py::arg("ChoixIso"));
cls_IntWalk_TheInt2S.def("IsDone", (Standard_Boolean (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::IsDone, "Returns TRUE if the creation completed without failure.");
cls_IntWalk_TheInt2S.def("IsEmpty", (Standard_Boolean (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::IsEmpty, "Returns TRUE when there is no solution to the problem.");
cls_IntWalk_TheInt2S.def("Point", (const IntSurf_PntOn2S & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::Point, "Returns the intersection point.");
cls_IntWalk_TheInt2S.def("IsTangent", (Standard_Boolean (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::IsTangent, "Returns True if the surfaces are tangent at the intersection point.");
cls_IntWalk_TheInt2S.def("Direction", (const gp_Dir & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::Direction, "Returns the tangent at the intersection line.");
cls_IntWalk_TheInt2S.def("DirectionOnS1", (const gp_Dir2d & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::DirectionOnS1, "Returns the tangent at the intersection line in the parametric space of the first surface.");
cls_IntWalk_TheInt2S.def("DirectionOnS2", (const gp_Dir2d & (IntWalk_TheInt2S::*)() const) &IntWalk_TheInt2S::DirectionOnS2, "Returns the tangent at the intersection line in the parametric space of the second surface.");
cls_IntWalk_TheInt2S.def("Function", (IntWalk_TheFunctionOfTheInt2S & (IntWalk_TheInt2S::*)()) &IntWalk_TheInt2S::Function, "return the math function which is used to compute the intersection");
cls_IntWalk_TheInt2S.def("ChangePoint", (IntSurf_PntOn2S & (IntWalk_TheInt2S::*)()) &IntWalk_TheInt2S::ChangePoint, "return the intersection point which is enable for changing.");

// CLASS: INTWALK_PWALKING
py::class_<IntWalk_PWalking> cls_IntWalk_PWalking(mod, "IntWalk_PWalking", "This class implements an algorithm to determine the intersection between 2 parametrized surfaces, marching from a starting point. The intersection line starts and ends on the natural surface's boundaries .");

// Constructors
cls_IntWalk_PWalking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Caro1"), py::arg("Caro2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntWalk_PWalking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Caro1"), py::arg("Caro2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

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


}
