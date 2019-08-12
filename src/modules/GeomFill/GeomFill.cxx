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

void bind_GeomFill_PipeError(py::module &);
void bind_GeomFill_Trihedron(py::module &);
void bind_GeomFill_ApproxStyle(py::module &);
void bind_GeomFill_FillingStyle(py::module &);
void bind_GeomFill_LocationLaw(py::module &);
void bind_GeomFill_Array1OfLocationLaw(py::module &);
void bind_GeomFill_HArray1OfLocationLaw(py::module &);
void bind_GeomFill_SequenceOfTrsf(py::module &);
void bind_GeomFill_SectionLaw(py::module &);
void bind_GeomFill_Array1OfSectionLaw(py::module &);
void bind_GeomFill_HArray1OfSectionLaw(py::module &);
void bind_GeomFill_Boundary(py::module &);
void bind_GeomFill_BoundWithSurf(py::module &);
void bind_GeomFill_SimpleBound(py::module &);
void bind_GeomFill_CornerState(py::module &);
void bind_GeomFill_ConstrainedFilling(py::module &);
void bind_GeomFill(py::module &);
void bind_GeomFill_AppSurf(py::module &);
void bind_GeomFill_AppSweep(py::module &);
void bind_GeomFill_BezierCurves(py::module &);
void bind_GeomFill_BSplineCurves(py::module &);
void bind_GeomFill_CircularBlendFunc(py::module &);
void bind_GeomFill_TrihedronLaw(py::module &);
void bind_GeomFill_ConstantBiNormal(py::module &);
void bind_GeomFill_Filling(py::module &);
void bind_GeomFill_Coons(py::module &);
void bind_GeomFill_CoonsAlgPatch(py::module &);
void bind_GeomFill_CorrectedFrenet(py::module &);
void bind_GeomFill_CurveAndTrihedron(py::module &);
void bind_GeomFill_Curved(py::module &);
void bind_GeomFill_Darboux(py::module &);
void bind_GeomFill_DegeneratedBound(py::module &);
void bind_GeomFill_SequenceOfAx2(py::module &);
void bind_GeomFill_HSequenceOfAx2(py::module &);
void bind_GeomFill_DiscreteTrihedron(py::module &);
void bind_GeomFill_DraftTrihedron(py::module &);
void bind_GeomFill_EvolvedSection(py::module &);
void bind_GeomFill_Fixed(py::module &);
void bind_GeomFill_Frenet(py::module &);
void bind_GeomFill_FunctionDraft(py::module &);
void bind_GeomFill_FunctionGuide(py::module &);
void bind_GeomFill_Profiler(py::module &);
void bind_GeomFill_Generator(py::module &);
void bind_GeomFill_TrihedronWithGuide(py::module &);
void bind_GeomFill_GuideTrihedronAC(py::module &);
void bind_GeomFill_GuideTrihedronPlan(py::module &);
void bind_GeomFill_Line(py::module &);
void bind_GeomFill_LocationDraft(py::module &);
void bind_GeomFill_LocationGuide(py::module &);
void bind_GeomFill_LocFunction(py::module &);
void bind_GeomFill_NSections(py::module &);
void bind_GeomFill_Pipe(py::module &);
void bind_GeomFill_PlanFunc(py::module &);
void bind_GeomFill_PolynomialConvertor(py::module &);
void bind_GeomFill_QuasiAngularConvertor(py::module &);
void bind_GeomFill_SectionGenerator(py::module &);
void bind_GeomFill_SectionPlacement(py::module &);
void bind_GeomFill_SnglrFunc(py::module &);
void bind_GeomFill_Stretch(py::module &);
void bind_GeomFill_Sweep(py::module &);
void bind_GeomFill_SweepFunction(py::module &);
void bind_GeomFill_SweepSectionGenerator(py::module &);
void bind_GeomFill_Tensor(py::module &);
void bind_GeomFill_TgtField(py::module &);
void bind_GeomFill_TgtOnCoons(py::module &);
void bind_GeomFill_UniformSection(py::module &);

PYBIND11_MODULE(GeomFill, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Law");
py::module::import("OCCT.Convert");
py::module::import("OCCT.AppBlend");
py::module::import("OCCT.Approx");
py::module::import("OCCT.math");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.TColGeom2d");

bind_GeomFill_PipeError(mod);
bind_GeomFill_Trihedron(mod);
bind_GeomFill_ApproxStyle(mod);
bind_GeomFill_FillingStyle(mod);
bind_GeomFill_LocationLaw(mod);
bind_GeomFill_Array1OfLocationLaw(mod);
bind_GeomFill_HArray1OfLocationLaw(mod);
bind_GeomFill_SequenceOfTrsf(mod);
bind_GeomFill_SectionLaw(mod);
bind_GeomFill_Array1OfSectionLaw(mod);
bind_GeomFill_HArray1OfSectionLaw(mod);
bind_GeomFill_Boundary(mod);
bind_GeomFill_BoundWithSurf(mod);
bind_GeomFill_SimpleBound(mod);
bind_GeomFill_CornerState(mod);
bind_GeomFill_ConstrainedFilling(mod);
bind_GeomFill(mod);
bind_GeomFill_AppSurf(mod);
bind_GeomFill_AppSweep(mod);
bind_GeomFill_BezierCurves(mod);
bind_GeomFill_BSplineCurves(mod);
bind_GeomFill_CircularBlendFunc(mod);
bind_GeomFill_TrihedronLaw(mod);
bind_GeomFill_ConstantBiNormal(mod);
bind_GeomFill_Filling(mod);
bind_GeomFill_Coons(mod);
bind_GeomFill_CoonsAlgPatch(mod);
bind_GeomFill_CorrectedFrenet(mod);
bind_GeomFill_CurveAndTrihedron(mod);
bind_GeomFill_Curved(mod);
bind_GeomFill_Darboux(mod);
bind_GeomFill_DegeneratedBound(mod);
bind_GeomFill_SequenceOfAx2(mod);
bind_GeomFill_HSequenceOfAx2(mod);
bind_GeomFill_DiscreteTrihedron(mod);
bind_GeomFill_DraftTrihedron(mod);
bind_GeomFill_EvolvedSection(mod);
bind_GeomFill_Fixed(mod);
bind_GeomFill_Frenet(mod);
bind_GeomFill_FunctionDraft(mod);
bind_GeomFill_FunctionGuide(mod);
bind_GeomFill_Profiler(mod);
bind_GeomFill_Generator(mod);
bind_GeomFill_TrihedronWithGuide(mod);
bind_GeomFill_GuideTrihedronAC(mod);
bind_GeomFill_GuideTrihedronPlan(mod);
bind_GeomFill_Line(mod);
bind_GeomFill_LocationDraft(mod);
bind_GeomFill_LocationGuide(mod);
bind_GeomFill_LocFunction(mod);
bind_GeomFill_NSections(mod);
bind_GeomFill_Pipe(mod);
bind_GeomFill_PlanFunc(mod);
bind_GeomFill_PolynomialConvertor(mod);
bind_GeomFill_QuasiAngularConvertor(mod);
bind_GeomFill_SectionGenerator(mod);
bind_GeomFill_SectionPlacement(mod);
bind_GeomFill_SnglrFunc(mod);
bind_GeomFill_Stretch(mod);
bind_GeomFill_Sweep(mod);
bind_GeomFill_SweepFunction(mod);
bind_GeomFill_SweepSectionGenerator(mod);
bind_GeomFill_Tensor(mod);
bind_GeomFill_TgtField(mod);
bind_GeomFill_TgtOnCoons(mod);
bind_GeomFill_UniformSection(mod);

}
