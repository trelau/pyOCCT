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
#include <math_MultipleVarFunction.hxx>
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <math_GlobOptMin.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_CellFilter.hxx>
#include <NCollection_Sequence.hxx>

void bind_math_GlobOptMin(py::module &mod){

py::class_<math_GlobOptMin> cls_math_GlobOptMin(mod, "math_GlobOptMin", "This class represents Evtushenko's algorithm of global optimization based on non-uniform mesh. Article: Yu. Evtushenko. Numerical methods for finding global extreme (case of a non-uniform mesh). U.S.S.R. Comput. Maths. Math. Phys., Vol. 11, N 6, pp. 38-54.");

// Constructors
cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"));
cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"));
cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"));
cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"), py::arg("theSameTol"));

// Fields

// Methods
cls_math_GlobOptMin.def("SetGlobalParams", [](math_GlobOptMin &self, math_MultipleVarFunction * a0, const math_Vector & a1, const math_Vector & a2) -> void { return self.SetGlobalParams(a0, a1, a2); });
cls_math_GlobOptMin.def("SetGlobalParams", [](math_GlobOptMin &self, math_MultipleVarFunction * a0, const math_Vector & a1, const math_Vector & a2, const Standard_Real a3) -> void { return self.SetGlobalParams(a0, a1, a2, a3); });
cls_math_GlobOptMin.def("SetGlobalParams", [](math_GlobOptMin &self, math_MultipleVarFunction * a0, const math_Vector & a1, const math_Vector & a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.SetGlobalParams(a0, a1, a2, a3, a4); });
cls_math_GlobOptMin.def("SetGlobalParams", (void (math_GlobOptMin::*)(math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real)) &math_GlobOptMin::SetGlobalParams, "", py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"), py::arg("theSameTol"));
cls_math_GlobOptMin.def("SetLocalParams", (void (math_GlobOptMin::*)(const math_Vector &, const math_Vector &)) &math_GlobOptMin::SetLocalParams, "Method to reduce bounding box. Perform will use this box.", py::arg("theLocalA"), py::arg("theLocalB"));
cls_math_GlobOptMin.def("SetTol", (void (math_GlobOptMin::*)(const Standard_Real, const Standard_Real)) &math_GlobOptMin::SetTol, "Method to set tolerances.", py::arg("theDiscretizationTol"), py::arg("theSameTol"));
cls_math_GlobOptMin.def("GetTol", [](math_GlobOptMin &self, Standard_Real & theDiscretizationTol, Standard_Real & theSameTol){ self.GetTol(theDiscretizationTol, theSameTol); return std::tuple<Standard_Real &, Standard_Real &>(theDiscretizationTol, theSameTol); }, "Method to get tolerances.", py::arg("theDiscretizationTol"), py::arg("theSameTol"));
cls_math_GlobOptMin.def("Perform", [](math_GlobOptMin &self) -> void { return self.Perform(); });
cls_math_GlobOptMin.def("Perform", (void (math_GlobOptMin::*)(const Standard_Boolean)) &math_GlobOptMin::Perform, "", py::arg("isFindSingleSolution"));
cls_math_GlobOptMin.def("Points", (void (math_GlobOptMin::*)(const Standard_Integer, math_Vector &)) &math_GlobOptMin::Points, "Return solution theIndex, 1 <= theIndex <= NbExtrema.", py::arg("theIndex"), py::arg("theSol"));
cls_math_GlobOptMin.def("SetContinuity", (void (math_GlobOptMin::*)(const Standard_Integer)) &math_GlobOptMin::SetContinuity, "Set / Get continuity of local borders splits (0 ~ C0, 1 ~ C1, 2 ~ C2).", py::arg("theCont"));
cls_math_GlobOptMin.def("GetContinuity", (Standard_Integer (math_GlobOptMin::*)() const) &math_GlobOptMin::GetContinuity, "None");
cls_math_GlobOptMin.def("SetFunctionalMinimalValue", (void (math_GlobOptMin::*)(const Standard_Real)) &math_GlobOptMin::SetFunctionalMinimalValue, "Set / Get functional minimal value.", py::arg("theMinimalValue"));
cls_math_GlobOptMin.def("GetFunctionalMinimalValue", (Standard_Real (math_GlobOptMin::*)() const) &math_GlobOptMin::GetFunctionalMinimalValue, "None");
cls_math_GlobOptMin.def("SetLipConstState", (void (math_GlobOptMin::*)(const Standard_Boolean)) &math_GlobOptMin::SetLipConstState, "Set / Get Lipchitz constant modification state. True means that the constant is locked and unlocked otherwise.", py::arg("theFlag"));
cls_math_GlobOptMin.def("GetLipConstState", (Standard_Boolean (math_GlobOptMin::*)() const) &math_GlobOptMin::GetLipConstState, "None");
cls_math_GlobOptMin.def("isDone", (Standard_Boolean (math_GlobOptMin::*)() const) &math_GlobOptMin::isDone, "Return computation state of the algorithm.");
cls_math_GlobOptMin.def("GetF", (Standard_Real (math_GlobOptMin::*)() const) &math_GlobOptMin::GetF, "Get best functional value.");
cls_math_GlobOptMin.def("NbExtrema", (Standard_Integer (math_GlobOptMin::*)() const) &math_GlobOptMin::NbExtrema, "Return count of global extremas.");

// Enums

}