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

void bind_FairCurve_AnalysisCode(py::module &);
void bind_FairCurve_Batten(py::module &);
void bind_FairCurve_BattenLaw(py::module &);
void bind_FairCurve_DistributionOfEnergy(py::module &);
void bind_FairCurve_DistributionOfJerk(py::module &);
void bind_FairCurve_DistributionOfSagging(py::module &);
void bind_FairCurve_DistributionOfTension(py::module &);
void bind_FairCurve_Energy(py::module &);
void bind_FairCurve_EnergyOfBatten(py::module &);
void bind_FairCurve_EnergyOfMVC(py::module &);
void bind_FairCurve_MinimalVariation(py::module &);
void bind_FairCurve_Newton(py::module &);

PYBIND11_MODULE(FairCurve, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");

bind_FairCurve_AnalysisCode(mod);
bind_FairCurve_Batten(mod);
bind_FairCurve_BattenLaw(mod);
bind_FairCurve_DistributionOfEnergy(mod);
bind_FairCurve_DistributionOfJerk(mod);
bind_FairCurve_DistributionOfSagging(mod);
bind_FairCurve_DistributionOfTension(mod);
bind_FairCurve_Energy(mod);
bind_FairCurve_EnergyOfBatten(mod);
bind_FairCurve_EnergyOfMVC(mod);
bind_FairCurve_MinimalVariation(mod);
bind_FairCurve_Newton(mod);

}
