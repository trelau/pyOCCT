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

void bind_XCAFDimTolObjects_DimensionModif(py::module &);
void bind_XCAFDimTolObjects_DatumSingleModif(py::module &);
void bind_XCAFDimTolObjects_DatumModifWithValue(py::module &);
void bind_XCAFDimTolObjects_DimensionFormVariance(py::module &);
void bind_XCAFDimTolObjects_DimensionGrade(py::module &);
void bind_XCAFDimTolObjects_DimensionType(py::module &);
void bind_XCAFDimTolObjects_DatumTargetType(py::module &);
void bind_XCAFDimTolObjects_DimensionQualifier(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceModif(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceType(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceTypeValue(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceMatReqModif(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceZoneModif(py::module &);
void bind_XCAFDimTolObjects_ToleranceZoneAffectedPlane(py::module &);
void bind_XCAFDimTolObjects_DimensionModifiersSequence(py::module &);
void bind_XCAFDimTolObjects_DatumModifiersSequence(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceObjectSequence(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceModifiersSequence(py::module &);
void bind_XCAFDimTolObjects_GeomToleranceObject(py::module &);
void bind_XCAFDimTolObjects_DatumObjectSequence(py::module &);
void bind_XCAFDimTolObjects_DatumObject(py::module &);
void bind_XCAFDimTolObjects_DataMapOfToleranceDatum(py::module &);
void bind_XCAFDimTolObjects_DimensionObjectSequence(py::module &);
void bind_XCAFDimTolObjects_DimensionObject(py::module &);
void bind_XCAFDimTolObjects_Tool(py::module &);

PYBIND11_MODULE(XCAFDimTolObjects, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDocStd");

bind_XCAFDimTolObjects_DimensionModif(mod);
bind_XCAFDimTolObjects_DatumSingleModif(mod);
bind_XCAFDimTolObjects_DatumModifWithValue(mod);
bind_XCAFDimTolObjects_DimensionFormVariance(mod);
bind_XCAFDimTolObjects_DimensionGrade(mod);
bind_XCAFDimTolObjects_DimensionType(mod);
bind_XCAFDimTolObjects_DatumTargetType(mod);
bind_XCAFDimTolObjects_DimensionQualifier(mod);
bind_XCAFDimTolObjects_GeomToleranceModif(mod);
bind_XCAFDimTolObjects_GeomToleranceType(mod);
bind_XCAFDimTolObjects_GeomToleranceTypeValue(mod);
bind_XCAFDimTolObjects_GeomToleranceMatReqModif(mod);
bind_XCAFDimTolObjects_GeomToleranceZoneModif(mod);
bind_XCAFDimTolObjects_ToleranceZoneAffectedPlane(mod);
bind_XCAFDimTolObjects_DimensionModifiersSequence(mod);
bind_XCAFDimTolObjects_DatumModifiersSequence(mod);
bind_XCAFDimTolObjects_GeomToleranceObjectSequence(mod);
bind_XCAFDimTolObjects_GeomToleranceModifiersSequence(mod);
bind_XCAFDimTolObjects_GeomToleranceObject(mod);
bind_XCAFDimTolObjects_DatumObjectSequence(mod);
bind_XCAFDimTolObjects_DatumObject(mod);
bind_XCAFDimTolObjects_DataMapOfToleranceDatum(mod);
bind_XCAFDimTolObjects_DimensionObjectSequence(mod);
bind_XCAFDimTolObjects_DimensionObject(mod);
bind_XCAFDimTolObjects_Tool(mod);

}
