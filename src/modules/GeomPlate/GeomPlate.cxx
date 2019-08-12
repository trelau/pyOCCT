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

void bind_GeomPlate_CurveConstraint(py::module &);
void bind_GeomPlate_SequenceOfCurveConstraint(py::module &);
void bind_GeomPlate_HSequenceOfCurveConstraint(py::module &);
void bind_GeomPlate_Array1OfSequenceOfReal(py::module &);
void bind_GeomPlate_HArray1OfSequenceOfReal(py::module &);
void bind_GeomPlate_PointConstraint(py::module &);
void bind_GeomPlate_SequenceOfPointConstraint(py::module &);
void bind_GeomPlate_HSequenceOfPointConstraint(py::module &);
void bind_GeomPlate_Array1OfHCurve(py::module &);
void bind_GeomPlate_HArray1OfHCurve(py::module &);
void bind_GeomPlate_BuildPlateSurface(py::module &);
void bind_GeomPlate_Aij(py::module &);
void bind_GeomPlate_SequenceOfAij(py::module &);
void bind_GeomPlate_BuildAveragePlane(py::module &);
void bind_GeomPlate_MakeApprox(py::module &);
void bind_GeomPlate_PlateG0Criterion(py::module &);
void bind_GeomPlate_PlateG1Criterion(py::module &);
void bind_GeomPlate_Surface(py::module &);

PYBIND11_MODULE(GeomPlate, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Law");
py::module::import("OCCT.GeomLProp");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColGeom2d");
py::module::import("OCCT.Plate");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.AdvApp2Var");
py::module::import("OCCT.GeomAbs");

bind_GeomPlate_CurveConstraint(mod);
bind_GeomPlate_SequenceOfCurveConstraint(mod);
bind_GeomPlate_HSequenceOfCurveConstraint(mod);
bind_GeomPlate_Array1OfSequenceOfReal(mod);
bind_GeomPlate_HArray1OfSequenceOfReal(mod);
bind_GeomPlate_PointConstraint(mod);
bind_GeomPlate_SequenceOfPointConstraint(mod);
bind_GeomPlate_HSequenceOfPointConstraint(mod);
bind_GeomPlate_Array1OfHCurve(mod);
bind_GeomPlate_HArray1OfHCurve(mod);
bind_GeomPlate_BuildPlateSurface(mod);
bind_GeomPlate_Aij(mod);
bind_GeomPlate_SequenceOfAij(mod);
bind_GeomPlate_BuildAveragePlane(mod);
bind_GeomPlate_MakeApprox(mod);
bind_GeomPlate_PlateG0Criterion(mod);
bind_GeomPlate_PlateG1Criterion(mod);
bind_GeomPlate_Surface(mod);

}
