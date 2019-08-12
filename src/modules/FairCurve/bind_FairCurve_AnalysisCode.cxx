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
#include <FairCurve_AnalysisCode.hxx>

void bind_FairCurve_AnalysisCode(py::module &mod){

py::enum_<FairCurve_AnalysisCode>(mod, "FairCurve_AnalysisCode", "To deal with different results in the computation of curvatures. - FairCurve_OK describes the case where computation is successfully completed - FairCurve_NotConverged describes the case where the algorithm does not converge. In this case, you can not be certain of the result quality and should resume computation if you want to make use of the curve. - FairCurve_InfiniteSliding describes the case where sliding is infinite, and, consequently, computation stops. The solution is to use an imposed sliding value. - FairCurve_NullHeight describes the case where no matter is left at one of the ends of the curve, and as a result, computation stops. The solution is to change (increase or reduce) the slope value by increasing or decreasing it.")
	.value("FairCurve_OK", FairCurve_AnalysisCode::FairCurve_OK)
	.value("FairCurve_NotConverged", FairCurve_AnalysisCode::FairCurve_NotConverged)
	.value("FairCurve_InfiniteSliding", FairCurve_AnalysisCode::FairCurve_InfiniteSliding)
	.value("FairCurve_NullHeight", FairCurve_AnalysisCode::FairCurve_NullHeight)
	.export_values();


}