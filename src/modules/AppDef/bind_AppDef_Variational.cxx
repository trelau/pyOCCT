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
#include <AppDef_MultiLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <GeomAbs_Shape.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <math_Matrix.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_OStream.hxx>
#include <AppDef_SmoothCriterion.hxx>
#include <FEmTool_Curve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <FEmTool_Assembly.hxx>
#include <math_Vector.hxx>
#include <PLib_Base.hxx>
#include <AppParCurves_Constraint.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppDef_Variational.hxx>

void bind_AppDef_Variational(py::module &mod){

py::class_<AppDef_Variational, std::unique_ptr<AppDef_Variational>> cls_AppDef_Variational(mod, "AppDef_Variational", "This class is used to smooth N points with constraints by minimization of quadratic criterium but also variational criterium in order to obtain ' fair Curve ' Computes the approximation of a Multiline by Variational optimization.");

// Constructors
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"), py::arg("WithCutting"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"), py::arg("WithCutting"), py::arg("Tolerance"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"), py::arg("WithCutting"), py::arg("Tolerance"), py::arg("NbIterations"));

// Fields

// Methods
// cls_AppDef_Variational.def_static("operator new_", (void * (*)(size_t)) &AppDef_Variational::operator new, "None", py::arg("theSize"));
// cls_AppDef_Variational.def_static("operator delete_", (void (*)(void *)) &AppDef_Variational::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Variational.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Variational::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Variational.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Variational::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Variational.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Variational::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Variational.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Variational::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Variational.def("Approximate", (void (AppDef_Variational::*)()) &AppDef_Variational::Approximate, "Makes the approximation with the current fields.");
cls_AppDef_Variational.def("IsCreated", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::IsCreated, "returns True if the creation is done and correspond to the current fields.");
cls_AppDef_Variational.def("IsDone", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::IsDone, "returns True if the approximation is ok and correspond to the current fields.");
cls_AppDef_Variational.def("IsOverConstrained", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::IsOverConstrained, "returns True if the problem is overconstrained in this case, approximation cannot be done.");
cls_AppDef_Variational.def("Value", (AppParCurves_MultiBSpCurve (AppDef_Variational::*)() const) &AppDef_Variational::Value, "returns all the BSpline curves approximating the MultiLine from AppDef SSP after minimization of the parameter.");
cls_AppDef_Variational.def("MaxError", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::MaxError, "returns the maximum of the distances between the points of the multiline and the approximation curves.");
cls_AppDef_Variational.def("MaxErrorIndex", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::MaxErrorIndex, "returns the index of the MultiPoint of ErrorMax");
cls_AppDef_Variational.def("QuadraticError", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::QuadraticError, "returns the quadratic average of the distances between the points of the multiline and the approximation curves.");
cls_AppDef_Variational.def("Distance", (void (AppDef_Variational::*)(math_Matrix &)) &AppDef_Variational::Distance, "returns the distances between the points of the multiline and the approximation curves.", py::arg("mat"));
cls_AppDef_Variational.def("AverageError", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::AverageError, "returns the average error between the MultiLine from AppDef and the approximation.");
cls_AppDef_Variational.def("Parameters", (const opencascade::handle<TColStd_HArray1OfReal> & (AppDef_Variational::*)() const) &AppDef_Variational::Parameters, "returns the parameters uses to the approximations");
cls_AppDef_Variational.def("Knots", (const opencascade::handle<TColStd_HArray1OfReal> & (AppDef_Variational::*)() const) &AppDef_Variational::Knots, "returns the knots uses to the approximations");
cls_AppDef_Variational.def("Criterium", [](AppDef_Variational &self, Standard_Real & VFirstOrder, Standard_Real & VSecondOrder, Standard_Real & VThirdOrder){ self.Criterium(VFirstOrder, VSecondOrder, VThirdOrder); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(VFirstOrder, VSecondOrder, VThirdOrder); }, "returns the values of the quality criterium.", py::arg("VFirstOrder"), py::arg("VSecondOrder"), py::arg("VThirdOrder"));
cls_AppDef_Variational.def("CriteriumWeight", [](AppDef_Variational &self, Standard_Real & Percent1, Standard_Real & Percent2, Standard_Real & Percent3){ self.CriteriumWeight(Percent1, Percent2, Percent3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Percent1, Percent2, Percent3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("Percent1"), py::arg("Percent2"), py::arg("Percent3"));
cls_AppDef_Variational.def("MaxDegree", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::MaxDegree, "returns the Maximum Degree used in the approximation");
cls_AppDef_Variational.def("MaxSegment", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::MaxSegment, "returns the Maximum of segment used in the approximation");
cls_AppDef_Variational.def("Continuity", (GeomAbs_Shape (AppDef_Variational::*)() const) &AppDef_Variational::Continuity, "returns the Continuity used in the approximation");
cls_AppDef_Variational.def("WithMinMax", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::WithMinMax, "returns if the approximation search to minimize the maximum Error or not.");
cls_AppDef_Variational.def("WithCutting", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::WithCutting, "returns if the approximation can insert new Knots or not.");
cls_AppDef_Variational.def("Tolerance", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::Tolerance, "returns the tolerance used in the approximation.");
cls_AppDef_Variational.def("NbIterations", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::NbIterations, "returns the number of iterations used in the approximation.");
cls_AppDef_Variational.def("Dump", (void (AppDef_Variational::*)(Standard_OStream &) const) &AppDef_Variational::Dump, "Prints on the stream o information on the current state of the object. MaxError,MaxErrorIndex,AverageError,QuadraticError,Criterium Distances,Degre,Nombre de poles, parametres, noeuds", py::arg("o"));
cls_AppDef_Variational.def("SetConstraints", (Standard_Boolean (AppDef_Variational::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &)) &AppDef_Variational::SetConstraints, "Define the constraints to approximate If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("aConstrainst"));
cls_AppDef_Variational.def("SetParameters", (void (AppDef_Variational::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_Variational::SetParameters, "Defines the parameters used by the approximations.", py::arg("param"));
cls_AppDef_Variational.def("SetKnots", (Standard_Boolean (AppDef_Variational::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_Variational::SetKnots, "Defines the knots used by the approximations If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("knots"));
cls_AppDef_Variational.def("SetMaxDegree", (Standard_Boolean (AppDef_Variational::*)(const Standard_Integer)) &AppDef_Variational::SetMaxDegree, "Define the Maximum Degree used in the approximation If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("Degree"));
cls_AppDef_Variational.def("SetMaxSegment", (Standard_Boolean (AppDef_Variational::*)(const Standard_Integer)) &AppDef_Variational::SetMaxSegment, "Define the maximum number of segments used in the approximation If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("NbSegment"));
cls_AppDef_Variational.def("SetContinuity", (Standard_Boolean (AppDef_Variational::*)(const GeomAbs_Shape)) &AppDef_Variational::SetContinuity, "Define the Continuity used in the approximation If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("C"));
cls_AppDef_Variational.def("SetWithMinMax", (void (AppDef_Variational::*)(const Standard_Boolean)) &AppDef_Variational::SetWithMinMax, "Define if the approximation search to minimize the maximum Error or not.", py::arg("MinMax"));
cls_AppDef_Variational.def("SetWithCutting", (Standard_Boolean (AppDef_Variational::*)(const Standard_Boolean)) &AppDef_Variational::SetWithCutting, "Define if the approximation can insert new Knots or not. If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("Cutting"));
cls_AppDef_Variational.def("SetCriteriumWeight", (void (AppDef_Variational::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_Variational::SetCriteriumWeight, "define the Weights (as percent) associed to the criterium used in the optimization.", py::arg("Percent1"), py::arg("Percent2"), py::arg("Percent3"));
cls_AppDef_Variational.def("SetCriteriumWeight", (void (AppDef_Variational::*)(const Standard_Integer, const Standard_Real)) &AppDef_Variational::SetCriteriumWeight, "define the Weight (as percent) associed to the criterium Order used in the optimization : Others weights are updated. if Percent < 0 if Order < 1 or Order > 3", py::arg("Order"), py::arg("Percent"));
cls_AppDef_Variational.def("SetTolerance", (void (AppDef_Variational::*)(const Standard_Real)) &AppDef_Variational::SetTolerance, "define the tolerance used in the approximation.", py::arg("Tol"));
cls_AppDef_Variational.def("SetNbIterations", (void (AppDef_Variational::*)(const Standard_Integer)) &AppDef_Variational::SetNbIterations, "define the number of iterations used in the approximation. if Iter < 1", py::arg("Iter"));

// Enums

}