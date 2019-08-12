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

void bind_Plate_PinpointConstraint(py::module &);
void bind_Plate_SequenceOfPinpointConstraint(py::module &);
void bind_Plate_Array1OfPinpointConstraint(py::module &);
void bind_Plate_HArray1OfPinpointConstraint(py::module &);
void bind_Plate_LinearXYZConstraint(py::module &);
void bind_Plate_SequenceOfLinearXYZConstraint(py::module &);
void bind_Plate_LinearScalarConstraint(py::module &);
void bind_Plate_SequenceOfLinearScalarConstraint(py::module &);
void bind_Plate_Plate(py::module &);
void bind_Plate_D1(py::module &);
void bind_Plate_D2(py::module &);
void bind_Plate_D3(py::module &);
void bind_Plate_FreeGtoCConstraint(py::module &);
void bind_Plate_GlobalTranslationConstraint(py::module &);
void bind_Plate_GtoCConstraint(py::module &);
void bind_Plate_LineConstraint(py::module &);
void bind_Plate_PlaneConstraint(py::module &);
void bind_Plate_SampledCurveConstraint(py::module &);

PYBIND11_MODULE(Plate, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.math");

bind_Plate_PinpointConstraint(mod);
bind_Plate_SequenceOfPinpointConstraint(mod);
bind_Plate_Array1OfPinpointConstraint(mod);
bind_Plate_HArray1OfPinpointConstraint(mod);
bind_Plate_LinearXYZConstraint(mod);
bind_Plate_SequenceOfLinearXYZConstraint(mod);
bind_Plate_LinearScalarConstraint(mod);
bind_Plate_SequenceOfLinearScalarConstraint(mod);
bind_Plate_Plate(mod);
bind_Plate_D1(mod);
bind_Plate_D2(mod);
bind_Plate_D3(mod);
bind_Plate_FreeGtoCConstraint(mod);
bind_Plate_GlobalTranslationConstraint(mod);
bind_Plate_GtoCConstraint(mod);
bind_Plate_LineConstraint(mod);
bind_Plate_PlaneConstraint(mod);
bind_Plate_SampledCurveConstraint(mod);

}
