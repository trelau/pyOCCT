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
#include <GeomAbs_SurfaceForm.hxx>

void bind_GeomAbs_SurfaceForm(py::module &mod){

py::enum_<GeomAbs_SurfaceForm>(mod, "GeomAbs_SurfaceForm", "This enumeration is used to note specific surface form.")
	.value("GeomAbs_PlanarForm", GeomAbs_SurfaceForm::GeomAbs_PlanarForm)
	.value("GeomAbs_ConicalForm", GeomAbs_SurfaceForm::GeomAbs_ConicalForm)
	.value("GeomAbs_CylindricalForm", GeomAbs_SurfaceForm::GeomAbs_CylindricalForm)
	.value("GeomAbs_ToroidalForm", GeomAbs_SurfaceForm::GeomAbs_ToroidalForm)
	.value("GeomAbs_SphericalForm", GeomAbs_SurfaceForm::GeomAbs_SphericalForm)
	.value("GeomAbs_RevolutionForm", GeomAbs_SurfaceForm::GeomAbs_RevolutionForm)
	.value("GeomAbs_RuledForm", GeomAbs_SurfaceForm::GeomAbs_RuledForm)
	.value("GeomAbs_QuadricForm", GeomAbs_SurfaceForm::GeomAbs_QuadricForm)
	.value("GeomAbs_OtherSurfaceForm", GeomAbs_SurfaceForm::GeomAbs_OtherSurfaceForm)
	.export_values();


}